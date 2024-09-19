// main.cpp
#include <iostream>
#include <memory>
#include "Node.h"
#include "Operation.h"
#include "OperationFactory.h"
#include "OperationRegistry.h"

int main() {
    // 注册预定义操作
    OperationRegistry::registerOperation("concat", [](const std::vector<std::shared_ptr<Node>>& inputs) -> std::string {
        if (inputs.size() < 2) {
            throw std::runtime_error("Concat operation requires at least two inputs.");
        }
        std::string result;
        for (const auto& node : inputs) {
            result += node->getString();
        }
        return result;
    });

    OperationRegistry::registerOperation("delete_first", [](const std::vector<std::shared_ptr<Node>>& inputs) -> std::string {
        if (inputs.empty()) {
            throw std::runtime_error("Delete operation requires at least one input.");
        }
        std::string original = inputs[0]->getString();
        if (!original.empty()) {
            return original.substr(1);
        }
        return original;
    });

    // 创建初始节点
    auto node_a = std::make_shared<Node>("Hello");
    auto node_b = std::make_shared<Node>("World");

    // 使用预定义的 concat 操作
    auto concatOp = OperationFactory::createOperation("concat", {node_a, node_b});
    auto concatNode = std::make_shared<Node>("", concatOp);
    concatNode->computeString(); // 计算并更新字符串值
    concatNode->printInfo();

    // 使用预定义的 delete_first 操作
    auto deleteOp = OperationFactory::createOperation("delete_first", {concatNode});
    auto deleteNode = std::make_shared<Node>("", deleteOp);
    deleteNode->computeString();
    deleteNode->printInfo();

    // 定义匿名操作并应用
    auto anonymousOpFunc = [](const std::vector<std::shared_ptr<Node>>& inputs) -> std::string {
        if (inputs.empty()) {
            throw std::runtime_error("Anonymous operation requires at least one input.");
        }
        return "[" + inputs[0]->getString() + "]";
    };
    auto anonymousOp = std::make_shared<Operation>(anonymousOpFunc, std::vector<std::shared_ptr<Node>>{deleteNode});
    auto anonymousNode = std::make_shared<Node>("", anonymousOp);
    anonymousNode->computeString();
    anonymousNode->printInfo();

    // 定义并注册自定义操作
    OperationRegistry::registerOperation("add_exclamation", [](const std::vector<std::shared_ptr<Node>>& inputs) -> std::string {
        if (inputs.empty()) {
            throw std::runtime_error("Add exclamation operation requires at least one input.");
        }
        return inputs[0]->getString() + "!";
    });

    // 使用自定义的 add_exclamation 操作
    auto exclaimOp = OperationFactory::createOperation("add_exclamation", {anonymousNode});
    auto exclaimNode = std::make_shared<Node>("", exclaimOp);
    exclaimNode->computeString();
    exclaimNode->printInfo();

    // 检查循环引用
    if (exclaimNode->hasLoop()) {
        std::cout << "Loop detected in the operation graph." << std::endl;
    } else {
        std::cout << "No loop detected in the operation graph." << std::endl;
    }

    // 验证字符串一致性
    if (exclaimNode->validateString()) {
        std::cout << "The stored string matches the computed string." << std::endl;
    } else {
        std::cout << "The stored string does not match the computed string." << std::endl;
    }

    return 0;
}
