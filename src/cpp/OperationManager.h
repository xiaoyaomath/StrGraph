#ifndef OPERATION_MANAGER_H
#define OPERATION_MANAGER_H

#include <string>
#include <unordered_map>
#include <memory>
#include "Operation.h"

class OperationManager {
public:
    static OperationManager& getInstance();

    std::shared_ptr<Operation> getOperation(const std::string& name) const;
    void registerOperation(const std::string& name, const std::shared_ptr<Operation>& op);
    void removeOperation(const std::string& name);
    void updateOperation(const std::string& name, const std::shared_ptr<Operation>& op);
    std::vector<std::string> listOperations() const;

private:
    OperationManager() = default;
    std::unordered_map<std::string, std::shared_ptr<Operation>> operations_;
};

#endif // OPERATION_MANAGER_H
