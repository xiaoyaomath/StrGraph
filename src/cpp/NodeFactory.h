#ifndef NODE_FACTORY_H
#define NODE_FACTORY_H

#include <memory>
#include <string>
#include <vector>
#include "Node.h"
#include "OperationManager.h"

class NodeFactory {
public:
    // 创建一个基础节点，包含字符串值
    static std::shared_ptr<Node> createValueNode(const std::string& value);

    // 创建一个带有操作的节点，操作名称通过字符串指定，输入节点作为参数
    static std::shared_ptr<Node> createOperationNode(const std::string& opName, const std::vector<std::shared_ptr<Node>>& inputNodes);
};

#endif // NODE_FACTORY_H
