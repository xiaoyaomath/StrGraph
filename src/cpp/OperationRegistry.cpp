// OperationRegistry.cpp
#include "OperationRegistry.h"

std::unordered_map<std::string, std::function<std::string(const std::vector<std::shared_ptr<Node>>&)> >&
OperationRegistry::getRegistry() {
    static std::unordered_map<std::string, std::function<std::string(const std::vector<std::shared_ptr<Node>>&)> > registry;
    return registry;
}

// 注册操作
void OperationRegistry::registerOperation(
    const std::string& name,
    const std::function<std::string(const std::vector<std::shared_ptr<Node>>&)> func) {
    auto& registry = getRegistry();
    registry[name] = func;
}

// 获取操作函数
std::function<std::string(const std::vector<std::shared_ptr<Node>>&)> OperationRegistry::getOperation(const std::string& name) {
    auto& registry = getRegistry();
    auto it = registry.find(name);
    if (it != registry.end()) {
        return it->second;
    }
    return nullptr;
}
