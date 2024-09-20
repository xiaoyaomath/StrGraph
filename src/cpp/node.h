#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Operation;

class Node {
public:
    Node(const std::string& value, std::shared_ptr<Operation> op = nullptr, const std::vector<std::shared_ptr<Node>>& inputNodes = {});

    std::string getString() const;
    std::string getSubstring(size_t pos, size_t len) const;

    void setString(const std::string& newValue);
    void setInputNodes(const std::vector<std::shared_ptr<Node>>& inputNodes);
    void setOperation(const std::shared_ptr<Operation>& op);

    std::string computeString();

    void printInfo() const;

    void updateOperationParams(const std::vector<int>& params);


private:
    std::string value_; 
    std::shared_ptr<Operation> operation_; 
    std::vector<std::shared_ptr<Node>> inputNodes_;
    mutable bool isUpdated_;
    mutable bool isComputing_;
};

#endif // NODE_H
