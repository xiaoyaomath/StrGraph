#include "Node.h"
#include "OperationManager.h"

Node::Node(const std::string& value, 
    std::shared_ptr<Operation> op, 
    const std::vector< std::shared_ptr<Node> >& inputNodes)
    : value_(value), operation_(op), inputNodes_(inputNodes), isComputing_(false), isUpdated_(true) {}

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
    std::cout << "Node Info:" << std::endl;
    std::cout << "  ID: " << id_ << std::endl;
    std::cout << "  Value: " << value_ << std::endl;
    if (operation_) {
        std::cout << "  Operation: " << operation_->getName() << std::endl;
        operation_->printInfo();
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
