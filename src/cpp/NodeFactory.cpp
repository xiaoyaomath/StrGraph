#include "NodeFactory.h"
#include "OperationManager.h"

// 创建基础节点，仅包含字符串值
std::shared_ptr<Node> NodeFactory::createValueNode(const std::string& value) {
    return std::make_shared<Node>(value);
}

// 创建带有操作的节点，操作通过名称获取，输入节点作为参数
std::shared_ptr<Node> NodeFactory::createOperationNode(const std::string& opName, const std::vector<std::shared_ptr<Node>>& inputNodes) {
    // 获取操作
    auto operation = OperationManager::getInstance().getOperation(opName);

    // 创建新的节点，传入操作和输入节点
    return std::make_shared<Node>("", operation, inputNodes);
}
