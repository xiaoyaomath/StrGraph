// Operation.h
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
    Operation(const std::function<std::string(const std::vector<std::shared_ptr<Node>>&)>& func,
              const std::vector<std::shared_ptr<Node>>& inputs,
              const std::string& name = "");

    // 获取输入节点的字符串列表
    std::vector<std::string> getInputStrings() const;

    // 获取操作名称
    std::string getName() const;

    // 运算：根据函数，输出结果字符串
    std::string compute();

    // 打印操作信息
    void printInfo() const;

    // 获取输入节点列表
    std::vector<std::shared_ptr<Node>> getInputNodes() const;

    // 复制操作
    std::shared_ptr<Operation> clone() const;

private:
    std::string name_; // 操作名称（可选）
    std::vector<std::shared_ptr<Node>> inputNodes_; // 输入节点指针列表
    std::function<std::string(const std::vector<std::shared_ptr<Node>>&)> func_; // 运算函数
};

#endif // OPERATION_H