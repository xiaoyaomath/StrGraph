// OperationFactory.h
#ifndef OPERATIONFACTORY_H
#define OPERATIONFACTORY_H

#include <string>
#include <vector>
#include <memory>
#include <functional>

class Node; // 前向声明
class Operation; // 前向声明

class OperationFactory {
public:
    // 创建操作
    static std::shared_ptr<Operation> createOperation(
        const std::string& name,
        const std::vector<std::shared_ptr<Node>>& inputs,
        const std::function<std::string(const std::vector<std::shared_ptr<Node>>&)> func = nullptr);
};

#endif // OPERATIONFACTORY_H