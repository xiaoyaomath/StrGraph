#include "Node.h"
#include "OperationList.h"
#include "OperationManager.h"

int main() {
    registerOperations();

    std::shared_ptr<Node> nodeA = std::make_shared<Node>("Hello");
    std::shared_ptr<Node> nodeB = std::make_shared<Node>("World");

    std::cout << "Node A: " << nodeA->getString() << std::endl;
    std::cout << "Node B: " << nodeB->getString() << std::endl;

    OperationManager& manager = OperationManager::getInstance();
    auto concatOperation = manager.getOperation("Concat");

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
