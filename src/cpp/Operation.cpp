#include "Operation.h"
#include "Node.h"

Operation::Operation(const std::function<std::string(const Node&, const std::vector<std::string>&)>& func,
                     const std::vector<std::string>& params,
                     const std::string& name)
    : func_(func), params_(params), name_(name) {
    if (!func_) {
        throw std::runtime_error("Operation must have a valid function.");
    }
}

// 运算：根据函数和参数，输出结果字符串
std::string Operation::compute(const Node& node) const {
    return func_(node, params_);
}

// 获取操作名称
std::string Operation::getName() const {
    return name_;
}

// 打印操作信息
void Operation::printInfo() const {
    std::cout << "Operation Info:" << std::endl;
    std::cout << "  Name: " << name_ << std::endl;
    std::cout << "  Params: ";
    for (const auto& param : params_) {
        std::cout << param << " ";
    }
    std::cout << std::endl;
}

// 复制操作
std::shared_ptr<Operation> Operation::clone() const {
    return std::make_shared<Operation>(func_, params_, name_);
}
