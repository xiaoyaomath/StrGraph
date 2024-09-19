// Operation.cpp
#include "Operation.h"
#include "Node.h"

Operation::Operation(const std::function<std::string(const std::vector<std::shared_ptr<Node>>&)>& func,
                     const std::vector<std::shared_ptr<Node>>& inputs,
                     const std::string& name)
    : func_(func), inputNodes_(inputs), name_(name) {
    if (!func_) {
        throw std::runtime_error("Operation must have a valid function.");
    }
}

// 获取输入节点的字符串列表
std::vector<std::string> Operation::getInputStrings() const {
    std::vector<std::string> strings;
    for (const auto& node : inputNodes_) {
        strings.push_back(node->getString());
    }
    return strings;
}

// 获取操作名称
std::string Operation::getName() const {
    return name_;
}

// 运算：根据函数，输出结果字符串
std::string Operation::compute() {
    return func_(inputNodes_);
}

// 打印操作信息
void Operation::printInfo() const {
    std::cout << "Operation Info:" << std::endl;
    std::cout << "  Name: " << (name_.empty() ? "Unnamed" : name_) << std::endl;
    std::cout << "  Input Strings: ";
    auto strings = getInputStrings();
    for (const auto& str : strings) {
        if (str.length() > 20) {
            std::cout << str.substr(0, 20) << "... ";
        } else {
            std::cout << str << " ";
        }
    }
    std::cout << std::endl;
}

// 获取输入节点列表
std::vector<std::shared_ptr<Node>> Operation::getInputNodes() const {
    return inputNodes_;
}

// 复制操作
std::shared_ptr<Operation> Operation::clone() const {
    return std::make_shared<Operation>(func_, inputNodes_, name_);
}