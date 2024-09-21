#include "Operation.h"
#include <iostream>
#include <algorithm>

// 构造函数，初始化操作对象，操作函数不可为空
Operation::Operation(const std::function<std::string(const std::vector<std::string>&)>& func,
                     const std::vector<int>& params,
                     const std::string& name)
    : func_(func), params_(params), name_(name) {
    if (!func_) {
        throw std::runtime_error("Operation must have a valid function.");
    }
}

std::string Operation::compute(const std::vector<std::string>& inputStrings) const {
    return func_(inputStrings);
}

std::string Operation::getName() const {
    return name_;
}

void Operation::printInfo() const {
    std::cout << "Operation Info:" << std::endl;
    std::cout << "  Name: " << name_ << std::endl;
    std::cout << "  Params: ";
    for (const auto& param : params_) {
        std::cout << param << " ";
    }
    std::cout << std::endl;
}

std::shared_ptr<Operation> Operation::clone() const {
    return std::make_shared<Operation>(func_, params_, name_);
}

void Operation::setParams(const std::vector<int>& params) {
    params_ = params;
}
