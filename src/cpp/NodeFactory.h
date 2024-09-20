#ifndef NODE_FACTORY_H
#define NODE_FACTORY_H

#include <memory>
#include <string>
#include <vector>
#include "Node.h"
#include "OperationManager.h"

class NodeFactory {
public:
    static std::shared_ptr<Node> createValueNode(const std::string& value);

    static std::shared_ptr<Node> createOperationNode(const std::string& opName, const std::vector<std::shared_ptr<Node>>& inputNodes);
};

#endif // NODE_FACTORY_H
