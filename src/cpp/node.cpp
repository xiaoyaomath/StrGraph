#include "Node.h"
#include "OperationManager.h"

Node::Node(const std::string& value, 
    std::shared_ptr<Operation> op, 
    const std::vector< std::shared_ptr<Node> >& inputNodes)
    : value_(value), operation_(op), inputNodes_(inputNodes), isComputing_(false), isUpdated_(true) {}

std::string Node::getString() const {
    return value_;
}

std::string Node::getSubstring(size_t pos, size_t len) const {
    if (pos >= value_.size()) {
        return "";
    }
    return value_.substr(pos, len);
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
        // 如果没有操作，返回当前节点的值
        return value_;
    }

    if (inputNodes_.empty()) {
        throw std::runtime_error("No input nodes set for this node.");
    }

    if (isComputing_) {
        throw std::runtime_error("Detected loop in computation.");
    }

    // 开始计算，防止循环调用
    isComputing_ = true;

    // 获取输入节点的计算结果
    std::vector<std::string> inputStrings;
    for (const auto& inputNode : inputNodes_) {
        if (!inputNode) {
            throw std::runtime_error("One of the input nodes is null.");
        }

        // 调用输入节点的计算方法
        std::string inputValue = inputNode->computeString();
        inputStrings.push_back(inputValue);
    }

    // 调用操作函数进行计算，更新节点的值
    value_ = operation_->compute(inputStrings);

    // 标记为最新计算值
    isUpdated_ = true;
    isComputing_ = false;

    // 返回新的计算值
    return value_;
}



void Node::printInfo() const {
    std::cout << "Node Info:" << std::endl;
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
