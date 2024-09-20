#include <gtest/gtest.h>
#include "NodeFactory.h"
#include "OperationManager.h"
#include "OperationList.h"

// 测试ConcatOperation操作
TEST(ConcatOperationTest, BasicConcat) {
    registerOperations();
    
    auto node1 = NodeFactory::createValueNode("Hello");
    auto node2 = NodeFactory::createValueNode("World");
    
    std::vector<std::shared_ptr<Node>> inputNodes = {node1, node2};
    auto concatNode = NodeFactory::createOperationNode("concat", inputNodes);
    
    std::string result = concatNode->computeString();
    
    EXPECT_EQ(result, "HelloWorld");
}

// 测试输入不足时的异常情况
TEST(ConcatOperationTest, InsufficientInputNodes) {
    registerOperations();

    auto node1 = NodeFactory::createValueNode("Hello");
    
    std::vector<std::shared_ptr<Node>> inputNodes = {node1};
    auto concatNode = NodeFactory::createOperationNode("concat", inputNodes);

    EXPECT_THROW({
        concatNode->computeString();
    }, std::runtime_error);
}

// 测试空字符串的情况
TEST(ConcatOperationTest, EmptyStringConcat) {
    registerOperations();

    auto node1 = NodeFactory::createValueNode("");
    auto node2 = NodeFactory::createValueNode("");

    std::vector<std::shared_ptr<Node>> inputNodes = {node1, node2};
    auto concatNode = NodeFactory::createOperationNode("concat", inputNodes);

    std::string result = concatNode->computeString();

    EXPECT_EQ(result, "");
}

// 测试混合空字符串和非空字符串
TEST(ConcatOperationTest, MixedStringConcat) {
    registerOperations();

    auto node1 = NodeFactory::createValueNode("Hello");
    auto node2 = NodeFactory::createValueNode("");

    std::vector<std::shared_ptr<Node>> inputNodes = {node1, node2};
    auto concatNode = NodeFactory::createOperationNode("concat", inputNodes);

    std::string result = concatNode->computeString();

    EXPECT_EQ(result, "Hello");
}

