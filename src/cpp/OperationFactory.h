#ifndef OPERATION_FACTORY_H
#define OPERATION_FACTORY_H

#include <unordered_map>
#include <string>
#include <functional>
#include "Operation.h"

class OperationFactory {
public:
    // 工厂方法：根据操作名称和参数创建 Operation
    static std::shared_ptr<Operation> createOperation(const std::string& opName, const std::vector<std::string>& params);

    // 注册操作：将操作名称与对应的函数关联
    static void registerOperation(const std::string& opName, const std::function<std::string(const Node&, const std::vector<std::string>&)>& func);

private:
    static std::unordered_map<std::string, std::function<std::string(const Node&, const std::vector<std::string>&)>> registry_;
};

#endif // OPERATION_FACTORY_H
