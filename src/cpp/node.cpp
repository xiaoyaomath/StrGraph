// Node.cpp
#include "Node.h"
#include "Operation.h"
#include "OperationRegistry.h"
#include "OperationFactory.h"

Node::Node(const std::string& value, std::shared_ptr<Operation> op)
    : value_(value), operation_(op), isComputing_(false) {}

// 获取节点存储的字符串
std::string Node::getString() const {
    return value_;
}

// 获取操作的输入节点指针列表
std::vector<std::shared_ptr<Node>> Node::getInputNodes() const {
    if (operation_) {
        return operation_->getInputNodes();
    }
    return {};
}

// 获取字符串的子串
std::string Node::getSubstring(size_t pos, size_t len) const {
    if (pos >= value_.size()) {
        return "";
    }
    return value_.substr(pos, len);
}

// 修改节点的字符串值
void Node::setString(const std::string& newValue) {
    value_ = newValue;
}

// 获取当前操作的输入节点数量
size_t Node::getOperationInputCount() const {
    if (operation_) {
        return operation_->getInputNodes().size();
    }
    return 0;
}

// 修改节点的操作，需检查输入节点数量是否匹配
void Node::setOperation(const std::shared_ptr<Operation>& newOperation) {
    if (!newOperation) {
        throw std::invalid_argument("New operation cannot be null.");
    }

    size_t currentInputCount = getOperationInputCount();
    size_t newInputCount = newOperation->getInputNodes().size();

    if (currentInputCount != newInputCount) {
        throw std::runtime_error("Input node count mismatch between current and new operation.");
    }

    operation_ = newOperation;
    computeString(); // 更新字符串值
}

// 获取节点的字符串值
std::string Node::getString() const {
    return value_;
}

// 计算字符串：通过调用操作的运算函数
std::string Node::computeString() {
    if (!operation_) {
        return value_;
    }

    // 防止循环计算
    if (isComputing_) {
        throw std::runtime_error("Detected loop in computation.");
    }

    isComputing_ = true;
    value_ = operation_->compute();
    isComputing_ = false;

    return value_;
}

// 验证存储的字符串和通过操作计算的字符串是否一致
bool Node::validateString() const {
    if (!operation_) {
        return true;
    }

    try {
        // 防止循环计算
        if (isComputing_) {
            throw std::runtime_error("Detected loop in validation.");
        }

        isComputing_ = true;
        std::string computedValue = operation_->compute();
        isComputing_ = false;

        return value_ == computedValue;
    } catch (const std::exception& e) {
        std::cerr << "Validation error: " << e.what() << std::endl;
        return false;
    }
}

// 根据操作名称，从注册表中修改操作
void Node::setOperation(const std::string& opName) {
    auto opFunc = OperationRegistry::getOperation(opName);
    if (opFunc) {
        operation_ = OperationFactory::createOperation(opName, getInputNodes(), opFunc);
        computeString(); // 更新字符串值
    } else {
        throw std::runtime_error("Operation not found in registry: " + opName);
    }
}

// 复制节点
std::shared_ptr<Node> Node::clone() const {
    auto clonedOp = operation_ ? operation_->clone() : nullptr;
    return std::make_shared<Node>(value_, clonedOp);
}

// 打印节点信息
void Node::printInfo() const {
    std::cout << "Node Info:" << std::endl;
    std::cout << "  Value: " << value_ << std::endl;
    if (operation_) {
        std::cout << "  Operation: " << operation_->getName() << std::endl;
        operation_->printInfo();
    } else {
        std::cout << "  Operation: None" << std::endl;
    }
}

// 判断是否存在循环引用
bool Node::hasLoop() const {
    std::unordered_set<const Node*> visitedNodes;
    return hasLoopHelper(visitedNodes);
}

bool Node::hasLoopHelper(std::unordered_set<const Node*>& visitedNodes) const {
    if (visitedNodes.find(this) != visitedNodes.end()) {
        return true; // 检测到循环
    }
    visitedNodes.insert(this);

    if (operation_) {
        for (const auto& inputNode : operation_->getInputNodes()) {
            if (inputNode->hasLoopHelper(visitedNodes)) {
                return true;
            }
        }
    }

    visitedNodes.erase(this);
    return false;
}