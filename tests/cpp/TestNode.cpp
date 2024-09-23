#include <gtest/gtest.h>
#include "Node.h"
#include "NodeFactory.h"
#include "OperationManager.h"
#include "OperationList.h"

TEST(NodeTest, CreateValueNode) {
    auto node = NodeFactory::createValueNode("Hello");
    EXPECT_EQ(node->getString(), "Hello");
    EXPECT_EQ(node->getInputNodes().size(), 0);
}

TEST(NodeTest, CreateOperationNode) {
    registerOperations();
    auto node1 = NodeFactory::createValueNode("Hello");
    auto node2 = NodeFactory::createValueNode("World");
    std::vector<std::shared_ptr<Node>> inputNodes = {node1, node2};
    auto concatNode = NodeFactory::createOperationNode("Concat", inputNodes);
    EXPECT_EQ(concatNode->getInputNodes().size(), 2);
    EXPECT_EQ(concatNode->computeString(), "HelloWorld");
}

TEST(NodeTest, SetAndGetString) {
    auto node = NodeFactory::createValueNode("Initial");
    EXPECT_EQ(node->getString(), "Initial");
    node->setString("Updated");
    EXPECT_EQ(node->getString(), "Updated");
}

TEST(NodeTest, ComputeStringValueNode) {
    auto node = NodeFactory::createValueNode("ValueNode");
    EXPECT_EQ(node->computeString(), "ValueNode");
}

TEST(NodeTest, ComputeStringOperationNode) {
    registerOperations();
    auto node1 = NodeFactory::createValueNode("Hello");
    auto node2 = NodeFactory::createValueNode("World");
    std::vector<std::shared_ptr<Node>> inputNodes = {node1, node2};
    auto concatNode = NodeFactory::createOperationNode("Concat", inputNodes);
    EXPECT_EQ(concatNode->computeString(), "HelloWorld");
}

TEST(NodeTest, SetAndGetInputNodes) {
    auto node1 = NodeFactory::createValueNode("Node1");
    auto node2 = NodeFactory::createValueNode("Node2");
    auto node = NodeFactory::createValueNode("Node");
    node->setInputNodes({node1, node2});
    auto inputs = node->getInputNodes();
    EXPECT_EQ(inputs.size(), 2);
    EXPECT_EQ(inputs[0]->getString(), "Node1");
    EXPECT_EQ(inputs[1]->getString(), "Node2");
}

TEST(NodeTest, UpdateOperationParams) {
    registerOperations();
    auto node = NodeFactory::createValueNode("HelloWorld");
    auto sliceNode = NodeFactory::createOperationNode("Slice", {node});
    sliceNode->updateOperationParams({0, 5});
    EXPECT_EQ(sliceNode->computeString(), "Hello");
}

TEST(NodeTest, LoopDetection) {
    auto node = NodeFactory::createValueNode("LoopNode");
    node->setInputNodes({node});
    EXPECT_THROW({
        node->computeString();
    }, std::runtime_error);
}

TEST(NodeTest, ComputeStringNoInputNodes) {
    registerOperations();
    auto concatNode = NodeFactory::createOperationNode("Concat", {});
    EXPECT_THROW({
        concatNode->computeString();
    }, std::runtime_error);
}

TEST(NodeTest, ComputeStringNoOperation) {
    auto node1 = NodeFactory::createValueNode("Hello");
    auto node2 = NodeFactory::createValueNode("World");
    auto node = std::make_shared<Node>("", nullptr, std::vector<std::shared_ptr<Node>>{node1, node2});
    EXPECT_THROW({
        node->computeString();
    }, std::runtime_error);
}
