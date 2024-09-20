// #include "Operation.h"
// #include <iostream>
// #include <algorithm>

// // 构造函数，初始化操作对象，操作函数不可为空
// Operation::Operation(const std::function<std::string(const std::vector<std::string>&)>& func,
//                      const std::vector<int>& params,
//                      const std::string& name)
//     : func_(func), params_(params), name_(name) {
//     if (!func_) {
//         throw std::runtime_error("Operation must have a valid function.");
//     }
// }

// std::string Operation::compute(const std::vector<std::string>& inputStrings) const {
//     return func_(inputStrings);
// }

// std::string Operation::getName() const {
//     return name_;
// }

// void Operation::printInfo() const {
//     std::cout << "Operation Info:" << std::endl;
//     std::cout << "  Name: " << name_ << std::endl;
//     std::cout << "  Params: ";
//     for (const auto& param : params_) {
//         std::cout << param << " ";
//     }
//     std::cout << std::endl;
// }

// std::shared_ptr<Operation> Operation::clone() const {
//     return std::make_shared<Operation>(func_, params_, name_);
// }

// void Operation::setParams(const std::vector<int>& params) {
//     params_ = params;
// }

#include "Node.h"
#include "OperationManager.h"
#include <algorithm>  // For std::remove_if

// Initialize static members
int Node::currentID = 0;
std::set<int> Node::existingNodeIds;
std::vector<std::weak_ptr<Node>> Node::allNodes_;

Node::Node(const std::string& value, 
    std::shared_ptr<Operation> op, 
    const std::vector<std::shared_ptr<Node>>& inputNodes)
    : value_(value), operation_(op), inputNodes_(inputNodes), isComputing_(false), isUpdated_(true) {

    // Assign the current ID and increment for the next node
    id_ = currentID++;
    
    // Add the node's ID to the set of existing node IDs
    existingNodeIds.insert(id_);
    
    // Add the node to the static vector tracking all nodes (weak pointer to avoid ownership issues)
    allNodes_.push_back(weak_from_this());
}

std::string Node::getString() const {
    return value_;
}

std::vector<std::shared_ptr<Node>> Node::getInputNodes() const {
    return inputNodes_;
}

void Node::setString(const std::string& newValue) {
    value_ = newValue;
    isUpdated_ = true;
}

void Node::setInputNodes(const std::vector<std::shared_ptr<Node>>& inputNodes) {
    inputNodes_ = inputNodes;
    isUpdated_ = false;
}

void Node::setOperation(const std::shared_ptr<Operation>& op) {
    operation_ = op; 
    isUpdated_ = false;
}

std::string Node::computeString() {
    if (!operation_) {
        return value_;
    }

    if (inputNodes_.empty()) {
        throw std::runtime_error("No input nodes set for this node.");
    }

    if (isComputing_) {
        throw std::runtime_error("Detected loop in computation.");
    }

    isComputing_ = true;

    std::vector<std::string> inputStrings;
    for (const auto& inputNode : inputNodes_) {
        if (!inputNode) {
            throw std::runtime_error("One of the input nodes is null.");
        }

        std::string inputValue = inputNode->computeString();
        inputStrings.push_back(inputValue);
    }

    value_ = operation_->compute(inputStrings);

    isUpdated_ = true;
    isComputing_ = false;

    return value_;
}

void Node::printInfo() const {
    std::cout << "Node Info:" << std::endl;
    std::cout << "  ID: " << id_ << std::endl;
    std::cout << "  Value: \"" << value_ << "\"" << std::endl;
    
    if (operation_) {
        std::cout << "  Operation: \"" << operation_->getName() << "\"" << std::endl;
    } else {
        std::cout << "  Operation: None" << std::endl;
    }
    
    if (!inputNodes_.empty()) {
        std::cout << "  Input Nodes Values: ";
        for (const auto& inputNode : inputNodes_) {
            std::cout << inputNode->getString() << " ";
        }
        std::cout << std::endl;
    }
}

void Node::updateOperationParams(const std::vector<int>& params) {
    if (operation_) {
        operation_->setParams(params);
        isUpdated_ = false;
    } else {
        throw std::runtime_error("No operation is set for this node.");
    }
}

void printIndent(int indentLevel) {
    for (int i = 0; i < indentLevel; ++i) {
        std::cout << "->";
    }
}

void Node::printGraph(int indentLevel) const {
    printIndent(indentLevel);
    std::cout << " Node: \"" << value_ << "\"";

    if (operation_) {
        std::cout << " Operation: \"" << operation_->getName() << "\"";
    } else {
        std::cout << " Operation: ";
    }

    std::cout << std::endl;

    for (const auto& inputNode : inputNodes_) {
        if (inputNode) {
            inputNode->printGraph(indentLevel + 1);  
        }
    }
}

// Static method to print all nodes
void Node::printAllNodes() {
    std::cout << "All Nodes:" << std::endl;
    for (const auto& weakNode : allNodes_) {
        if (auto node = weakNode.lock()) { // Only print if the node is still alive
            std::cout << "ID: " << node->id_ << ", Value: \"" << node->value_ << "\", ";
            if (node->operation_) {
                std::cout << "Operation: \"" << node->operation_->getName() << "\"";
            } else {
                std::cout << "Operation: None";
            }
            std::cout << std::endl;
        }
    }
}

// Method to delete a node (removes it from the tracking set and lets it be deleted by shared_ptr)
void Node::deleteNode() {
    // Remove the node's ID from the set of existing node IDs
    existingNodeIds.erase(id_);

    // Remove the node's reference in the static tracking list
    auto it = std::remove_if(allNodes_.begin(), allNodes_.end(), [this](const std::weak_ptr<Node>& weakNode) {
        auto node = weakNode.lock();
        return node && node->id_ == this->id_;
    });

    allNodes_.erase(it, allNodes_.end());

    // After removing the node from tracking, reset the shared_ptr to free memory
    std::shared_ptr<Node> self = shared_from_this();
    self.reset();  // This will decrement the reference count and delete the object if no other references exist
}
