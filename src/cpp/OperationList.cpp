#include "OperationList.h"
#include "OperationManager.h"
#include "Node.h"

//连接操作
std::string ConcatOperation(const std::vector<std::string>& inputStrings) {
    if (inputStrings.size() < 2) {
        throw std::runtime_error("Concat operation requires at least two input nodes.");
    }
    return inputStrings[0] + inputStrings[1];
}


// 注册所有操作
void registerOperations() {
    auto& manager = OperationManager::getInstance();

    manager.registerOperation("concat", std::make_shared<Operation>(
        std::function<std::string(const std::vector<std::string>&)>(ConcatOperation),
        std::vector<std::string>{}, "concat")
    );
}
