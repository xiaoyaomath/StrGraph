#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Operation; // 前向声明

class Node {
public:
    Node(const std::string& value, std::shared_ptr<Operation> op = nullptr, const std::vector<std::shared_ptr<Node>>& inputNodes = {});

    std::string getString() const;
    std::string getSubstring(size_t pos, size_t len) const;

    void setString(const std::string& newValue);
    void setInputNodes(const std::vector<std::shared_ptr<Node>>& inputNodes);
    void setOperation(const std::shared_ptr<Operation>& op);

    std::string computeString();

    void printInfo() const;

private:
    std::string value_; // 节点存储的值
    std::shared_ptr<Operation> operation_; // 节点的操作（可选）
    std::vector<std::shared_ptr<Node>> inputNodes_; // 节点的输入节点（可选）
    mutable bool isUpdated_; // 节点的计算状态
    mutable bool isComputing_; // 检测是否在计算中，用于防止循环依赖
};

#endif // NODE_H
