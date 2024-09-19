// OperationRegistry.h
#ifndef OPERATIONREGISTRY_H
#define OPERATIONREGISTRY_H

#include <string>
#include <functional>
#include <vector>
#include <memory>
#include <unordered_map>

class Node; // 前向声明

class OperationRegistry {
public:
    // 注册操作
    static void registerOperation(
        const std::string& name,
        const std::function<std::string(const std::vector<std::shared_ptr<Node>>&)> func);

    // 获取操作函数
    static std::function<std::string(const std::vector<std::shared_ptr<Node>>&)> getOperation(const std::string& name);

private:
    static std::unordered_map<std::string, std::function<std::string(const std::vector<std::shared_ptr<Node>>&)> >& getRegistry();
};

#endif // OPERATIONREGISTRY_H
