#include <gtest/gtest.h>
#include "NodeFactory.h"
#include "OperationManager.h"
#include "OperationList.h"

TEST(NodeFactoryTest, CreateValueNode) {
    auto node = NodeFactory::createValueNode("TestValue");
    EXPECT_EQ(node->getString(), "TestValue");
    EXPECT_EQ(node->getInputNodes().size(), 0);
}

TEST(NodeFactoryTest, CreateOperationNodeExistingOp) {
    registerOperations();
    auto node1 = NodeFactory::createValueNode("Hello");
    auto node2 = NodeFactory::createValueNode("World");
    auto concatNode = NodeFactory::createOperationNode("Concat", {node1, node2});
    EXPECT_EQ(concatNode->getInputNodes().size(), 2);
    EXPECT_EQ(concatNode->computeString(), "HelloWorld");
}

TEST(NodeFactoryTest, CreateOperationNodeNonExistingOp) {
    auto node1 = NodeFactory::createValueNode("Hello");
    auto node2 = NodeFactory::createValueNode("World");
    EXPECT_THROW({
        auto invalidOpNode = NodeFactory::createOperationNode("NonExistingOp", {node1, node2});
    }, std::runtime_error);
}
