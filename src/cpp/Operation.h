#ifndef OPERATION_H
#define OPERATION_H

#include <string>
#include <vector>
#include <memory>
#include <functional>

class Node; // 前向声明

class Operation {
public:
    // 构造函数：必须定义运算函数，否则抛出异常
    Operation(const std::function<std::string(const Node&, const std::vector<std::string>&)>& func,
              const std::vector<std::string>& params = {},
              const std::string& name = "");

    // 运算：根据函数和参数，输出结果字符串
    std::string compute(const Node& node) const;

    // 获取操作名称
    std::string getName() const;

    // 打印操作信息
    void printInfo() const;

    // 复制操作
    std::shared_ptr<Operation> clone() const;

private:
    std::string name_; // 操作名称
    std::vector<std::string> params_; // 参数
    std::function<std::string(const Node&, const std::vector<std::string>&)> func_; // 运算函数
};

#endif // OPERATION_H
