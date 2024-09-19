// OperationFactory.cpp
#include "OperationFactory.h"
#include "Operation.h"
#include "OperationRegistry.h"

std::shared_ptr<Operation> OperationFactory::createOperation(
    const std::string& name,
    const std::vector<std::shared_ptr<Node>>& inputs,
    const std::function<std::string(const std::vector<std::shared_ptr<Node>>&)> func) {

    std::function<std::string(const std::vector<std::shared_ptr<Node>>&)> opFunc = func;

    if (!opFunc) {
        opFunc = OperationRegistry::getOperation(name);
        if (!opFunc) {
            throw std::runtime_error("Operation not found in registry: " + name);
        }
    }

    return std::make_shared<Operation>(opFunc, inputs, name);
}
