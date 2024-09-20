#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class Operation;

// Initialize static members
int Node::currentID = 0;
std::set<int> Node::existingNodeIds;
std::vector<std::weak_ptr<Node>> Node::allNodes_;

class Node {
public:
    Node(const std::string& value, std::shared_ptr<Operation> op = nullptr, const std::vector<std::shared_ptr<Node>>& inputNodes = {});

    std::string getString() const;
    std::vector<std::shared_ptr<Node>> getInputNodes() const;
    void setString(const std::string& newValue);
    void setInputNodes(const std::vector<std::shared_ptr<Node>>& inputNodes);
    void setOperation(const std::shared_ptr<Operation>& op);

    std::string computeString();

    void printInfo() const;

    void updateOperationParams(const std::vector<int>& params);

    void printGraph(int indentLevel = 0) const;

    // Delete this node and free its memory by resetting its shared_ptr
    void deleteNode();

    static void printAllNodes();


private:
    std::string value_; 
    std::shared_ptr<Operation> operation_; 
    std::vector<std::shared_ptr<Node>> inputNodes_;
    mutable bool isUpdated_;
    mutable bool isComputing_;
    int id_;

    static int currentID;
    static std::set<int> existingNodeIds;
    static std::vector<std::weak_ptr<Node>> allNodes_;
};

#endif // NODE_H
