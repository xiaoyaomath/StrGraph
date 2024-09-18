#include <gtest/gtest.h>
#include <memory>
#include <string>
#include "twoStringOperations.h"
#include "node.h"

// 测试 ConcatOperation 类的行为
TEST(NodeTest, ConcatOperationTest) {
    std::string str1 = "Hello";
    std::string str2 = " World";

    // 创建 ConcatOperation 对象
    auto concat_operation = std::make_shared<ConcatOperation>(&str1, &str2);

    // 创建 Node 对象并设置操作
    Node node("Initial");
    node.set_operation(concat_operation);

    // 测试是否正确连接字符串
    EXPECT_EQ(node.apply_operation(), "Hello World");
}

TEST(NodeTest, ConcatOperationEmptyTest) {
    std::string str1 = "";
    std::string str2 = "";

    // 创建空字符串的 ConcatOperation
    auto concat_operation = std::make_shared<ConcatOperation>(&str1, &str2);

    Node node("Initial");
    node.set_operation(concat_operation);

    // 测试空字符串连接的情况
    EXPECT_EQ(node.apply_operation(), "");
}

TEST(NodeTest, ConcatOperationSingleEmptyTest) {
    std::string str1 = "Hello";
    std::string str2 = "";

    // 测试其中一个为空字符串的情况
    auto concat_operation = std::make_shared<ConcatOperation>(&str1, &str2);

    Node node("Initial");
    node.set_operation(concat_operation);

    // 结果应该是只返回非空字符串
    EXPECT_EQ(node.apply_operation(), "Hello");
}

// 测试 Node 类的基础功能
TEST(NodeTest, DefaultValue) {
    Node node("Test String");

    // 测试节点的初始值是否正确
    EXPECT_EQ(node.get_value(), "Test String");
}

TEST(NodeTest, SetValue) {
    Node node("Old Value");
    node.set_value("New Value");

    // 测试值是否可以更新
    EXPECT_EQ(node.get_value(), "New Value");
}

TEST(NodeTest, NoOperation) {
    Node node("No Operation");

    // 当没有设置操作时，应该返回原始值
    EXPECT_EQ(node.apply_operation(), "No Operation");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
