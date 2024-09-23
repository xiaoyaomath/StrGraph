#include <gtest/gtest.h>
#include "Operation.h"

TEST(OperationTest, CreateValidOperation) {
    auto func = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        return inputs[0] + inputs[1];
    };
    auto op = std::make_shared<Operation>(func, std::vector<int>{}, "TestConcat");
    EXPECT_EQ(op->getName(), "TestConcat");
    EXPECT_EQ(op->getParams().size(), 0);
}

TEST(OperationTest, CreateInvalidOperation) {
    std::function<std::string(const std::vector<std::string>&, const std::vector<int>&)> func; // 空函数
    EXPECT_THROW({
        auto op = std::make_shared<Operation>(func, std::vector<int>{}, "InvalidOp");
    }, std::runtime_error);
}

TEST(OperationTest, ComputeValidInputs) {
    auto func = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        return inputs[0] + inputs[1];
    };
    auto op = std::make_shared<Operation>(func, std::vector<int>{}, "TestConcat");
    std::vector<std::string> inputs = {"Hello", "World"};
    EXPECT_EQ(op->compute(inputs), "HelloWorld");
}

TEST(OperationTest, ComputeInsufficientInputs) {
    auto func = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        if (inputs.size() < 2) {
            throw std::runtime_error("Insufficient inputs");
        }
        return inputs[0] + inputs[1];
    };
    auto op = std::make_shared<Operation>(func, std::vector<int>{}, "TestConcat");
    std::vector<std::string> inputs = {"Hello"};
    EXPECT_THROW({
        op->compute(inputs);
    }, std::runtime_error);
}

TEST(OperationTest, SetAndGetParams) {
    auto func = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        return inputs[0];
    };
    auto op = std::make_shared<Operation>(func, std::vector<int>{1, 2}, "TestOp");
    EXPECT_EQ(op->getParams(), std::vector<int>({1, 2}));
    op->setParams({3, 4});
    EXPECT_EQ(op->getParams(), std::vector<int>({3, 4}));
}

TEST(OperationTest, SetAndGetName) {
    auto func = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        return inputs[0];
    };
    auto op = std::make_shared<Operation>(func, std::vector<int>{}, "InitialName");
    EXPECT_EQ(op->getName(), "InitialName");
    op->setName("UpdatedName");
    EXPECT_EQ(op->getName(), "UpdatedName");
}

TEST(OperationTest, SetFunc) {
    auto func1 = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        return inputs[0];
    };
    auto func2 = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        return inputs[0] + inputs[0];
    };
    auto op = std::make_shared<Operation>(func1, std::vector<int>{}, "TestOp");
    std::vector<std::string> inputs = {"Hello"};
    EXPECT_EQ(op->compute(inputs), "Hello");
    op->setFunc(func2);
    EXPECT_EQ(op->compute(inputs), "HelloHello");
}

TEST(OperationTest, SetInvalidFunc) {
    auto func1 = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        return inputs[0];
    };
    std::function<std::string(const std::vector<std::string>&, const std::vector<int>&)> func2; // 空函数
    auto op = std::make_shared<Operation>(func1, std::vector<int>{}, "TestOp");
    EXPECT_THROW({
        op->setFunc(func2);
    }, std::runtime_error);
}

TEST(OperationTest, CloneOperation) {
    auto func = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        return inputs[0];
    };
    auto op = std::make_shared<Operation>(func, std::vector<int>{1}, "TestOp");
    auto opClone = op->clone();
    EXPECT_EQ(opClone->getName(), "TestOp");
    EXPECT_EQ(opClone->getParams(), std::vector<int>({1}));
}
