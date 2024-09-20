#include "OperationManager.h"
#include <iostream>

OperationManager& OperationManager::getInstance() {
    static OperationManager instance;
    return instance;
}

std::shared_ptr<Operation> OperationManager::getOperation(const std::string& name) const {
    auto it = operations_.find(name);
    if (it != operations_.end()) {
        return it->second;
    }
    throw std::runtime_error("Operation not found: " + name);
}

void OperationManager::registerOperation(const std::string& name, const std::shared_ptr<Operation>& op) {
    if (operations_.count(name) > 0) {
        throw std::runtime_error("Operation already exists: " + name);
    }
    operations_[name] = op;
}

void OperationManager::removeOperation(const std::string& name) {
    if (operations_.erase(name) == 0) {
        throw std::runtime_error("Operation not found: " + name);
    }
}

void OperationManager::updateOperation(const std::string& name, const std::shared_ptr<Operation>& op) {
    if (operations_.count(name) == 0) {
        throw std::runtime_error("Operation not found: " + name);
    }
    operations_[name] = op;
}

void OperationManager::listOperations() const {
    std::cout << "Available operations:" << std::endl;
    for (const auto& entry : operations_) {
        std::cout << "  - " << entry.first << std::endl;
    }
}
