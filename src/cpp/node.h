// Node.h
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_set>

class Operation; // 前向声明

class Node {
public:
    // 构造函数：根据字符串和操作构造节点，默认为空操作
    Node(const std::string& value, std::shared_ptr<Operation> op = nullptr);

    // 获取节点存储的字符串
    std::string getString() const;

    // 获取操作的输入节点指针列表
    std::vector<std::shared_ptr<Node>> getInputNodes() const;

    // 获取字符串的子串
    std::string getSubstring(size_t pos, size_t len) const;

    // 修改节点的字符串值
    void setString(const std::string& newValue);

    // 修改节点的操作，需检查输入节点数量是否匹配
    void setOperation(const std::shared_ptr<Operation>& newOperation);

    // 获取当前操作的输入节点数量
    size_t getOperationInputCount() const;

    // 获取节点的字符串值
    std::string getString() const;

    // 计算字符串：通过调用操作的运算函数
    std::string computeString();

    // 验证存储的字符串和通过操作计算的字符串是否一致
    bool validateString() const;

    // 根据操作名称，从注册表中修改操作
    void setOperation(const std::string& opName);

    // 复制节点
    std::shared_ptr<Node> clone() const;

    // 打印节点信息：调用操作的名字，打印节点信息
    void printInfo() const;

    // 判断是否存在循环引用
    bool hasLoop() const;

private:
    std::string value_;                           // 节点存储的字符串
    std::shared_ptr<Operation> operation_;        // 关联的操作
    mutable bool isComputing_;                    // 标记是否正在计算，防止循环

    // 辅助函数：用于循环检测
    bool hasLoopHelper(std::unordered_set<const Node*>& visitedNodes) const;
};

#endif // NODE_H