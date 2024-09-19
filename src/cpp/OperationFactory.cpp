#include "OperationFactory.h"
#include "Node.h"

// 静态成员的初始化
std::unordered_map<std::string, std::function<std::string(const Node&, const std::vector<std::string>&)>> OperationFactory::registry_;

std::shared_ptr<Operation> OperationFactory::createOperation(const std::string& opName, const std::vector<std::string>& params) {
    auto it = registry_.find(opName);
    if (it != registry_.end()) {
        return std::make_shared<Operation>(it->second, params, opName);
    }
    throw std::runtime_error("Operation not found: " + opName);
}

void OperationFactory::registerOperation(const std::string& opName, const std::function<std::string(const Node&, const std::vector<std::string>&)>& func) {
    registry_[opName] = func;
}
