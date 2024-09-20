#include "NodeFactory.h"
#include "OperationManager.h"


std::shared_ptr<Node> NodeFactory::createValueNode(const std::string& value) {
    return std::make_shared<Node>(value);
}


std::shared_ptr<Node> NodeFactory::createOperationNode(const std::string& opName, const std::vector<std::shared_ptr<Node>>& inputNodes) {
    auto operation = OperationManager::getInstance().getOperation(opName);
    return std::make_shared<Node>("", operation, inputNodes);
}
