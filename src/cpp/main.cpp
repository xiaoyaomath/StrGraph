#include "Node.h"
#include "OperationList.h"
#include "OperationManager.h"

int main() {
    // 注册操作
    registerOperations();

    // 创建两个基础节点
    std::shared_ptr<Node> nodeA = std::make_shared<Node>("Hello");
    std::shared_ptr<Node> nodeB = std::make_shared<Node>("World");

    // 输出基础节点的值，确保它们正确创建
    std::cout << "Node A: " << nodeA->getString() << std::endl;
    std::cout << "Node B: " << nodeB->getString() << std::endl;

    // 获取 "concat" 操作
    OperationManager& manager = OperationManager::getInstance();
    auto concatOperation = manager.getOperation("concat");

    std::cout << "manager: " << std::endl;
    manager.listOperations();

    std::cout << "concatOp: " << concatOperation->getName() << std::endl;

    std::shared_ptr<Node> concatNode = std::make_shared<Node>("xyz", concatOperation, std::vector<std::shared_ptr<Node>>{nodeA, nodeB});

    std::cout << "Concat Node Input A: " << nodeA->getString() << std::endl;
    std::cout << "Concat Node Input B: " << nodeB->getString() << std::endl;
    std::cout << "concat Node's string: " << concatNode->getString() << std::endl;

    std::string result = concatNode->computeString();

    std::cout << "Concatenated result: " << result << std::endl;
    std::cout << "concat Node's new string: " << concatNode->getString() << std::endl;

    return 0;
}
