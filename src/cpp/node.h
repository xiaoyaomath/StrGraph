#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class Operation;

class Node {
public:
    Node(const std::string& value, std::shared_ptr<Operation> op = nullptr, const std::vector<std::shared_ptr<Node>>& inputNodes = {});

    std::string getString() const;
    int getId() const;
    std::vector<std::shared_ptr<Node>> getInputNodes() const;
    void setString(const std::string& newValue);
    void setInputNodes(const std::vector<std::shared_ptr<Node>>& inputNodes);
    void setOperation(const std::shared_ptr<Operation>& op);

    std::string computeString();
    void computeGraph() const; 

    void printInfo() const;

    void updateOperationParams(const std::vector<int>& params);

    void printGraph(int indentLevel = 0) const;

    static void printAllNodes();


private:
    std::string value_; 
    std::shared_ptr<Operation> operation_; 
    std::vector<std::shared_ptr<Node>> inputNodes_;
    mutable bool isUpdated_;
    mutable bool isComputing_;
    int id_;

    static int currentID;
};

#endif // NODE_H
