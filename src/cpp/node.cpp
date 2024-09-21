#include "Node.h"
#include "OperationManager.h"
#include <queue>
#include <stack>

int Node::currentID = 0;

Node::Node(const std::string& value, 
    std::shared_ptr<Operation> op, 
    const std::vector< std::shared_ptr<Node> >& inputNodes)
    : value_(value), operation_(op), inputNodes_(inputNodes), isComputing_(false), isUpdated_(true) {
        id_ = ++currentID;
    }

std::string Node::getString() const {
    return value_;
}

int Node::getId() const{
    return id_;
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

void Node::computeGraph() const {
    std::queue<std::shared_ptr<Node>> bfsQueue;
    std::vector<std::shared_ptr<Node>> traversalOrder;

    // Start BFS from the current node
    bfsQueue.push(std::make_shared<Node>(*this));

    // Perform BFS traversal
    while (!bfsQueue.empty()) {
        std::shared_ptr<Node> currentNode = bfsQueue.front();
        bfsQueue.pop();

        // Add the current node to the traversal order
        traversalOrder.push_back(currentNode);

        // Push all input nodes into the queue
        for (const auto& inputNode : currentNode->getInputNodes()) {
            if (inputNode) {
                bfsQueue.push(inputNode);
            }
        }
    }

    // Print the traversal order
    std::cout << "BFS Traversal Order: ";
    for (const auto& node : traversalOrder) {
        std::cout << node->getId() << ", ";
    }
    std::cout << std::endl;

    // Reverse the traversal order
    std::reverse(traversalOrder.begin(), traversalOrder.end());

    // Compute the strings in reverse order
    std::cout << "Computing in reverse order:" << std::endl;
    for (const auto& node : traversalOrder) {
        std::cout << "Computing Node " << node->getId() << ": " << node->computeString() << std::endl;
    }
}

void Node::printInfo() const {
    std::cout << "Node Info: ID: " << id_ << " : \"" << value_ << "\"";
    
    if (operation_) {
        std::cout << "  Operation: " << operation_->getName() << std::endl;
        operation_->printInfo();
    } else {
        std::cout << "  Operation: None" << std::endl;
    }

    if (!inputNodes_.empty()) {
        std::cout << "  Input Nodes Values: ";
        for (const auto& inputNode : inputNodes_) {
            std::cout << "\"" << inputNode->getString() << "\" ";
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
    std::cout << " Node "<< id_ <<": \"" << value_ << "\"";
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
