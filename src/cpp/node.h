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

    // 获取字符串的子串
    std::string getSubstring(size_t pos, size_t len) const;

    // 修改节点的字符串值
    void setString(const std::string& newValue);

    // 设置操作（通过工厂动态创建）
    void setOperation(const std::string& opName, const std::vector<std::string>& params);

    // 计算字符串
    std::string computeString();

    // 复制节点
    std::shared_ptr<Node> clone() const;

    // 打印节点信息
    void printInfo() const;

private:
    std::string value_;                           // 节点存储的字符串
    std::shared_ptr<Operation> operation_;        // 关联的操作
    mutable bool isComputing_;                    // 防止循环计算
};

#endif // NODE_H
