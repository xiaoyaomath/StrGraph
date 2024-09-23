#include <gtest/gtest.h>
#include "OperationManager.h"
#include "Operation.h"
#include "OperationList.h"

TEST(OperationManagerTest, GetInstance) {
    OperationManager& manager1 = OperationManager::getInstance();
    OperationManager& manager2 = OperationManager::getInstance();
    EXPECT_EQ(&manager1, &manager2);
}

TEST(OperationManagerTest, RegisterAndGetOperation) {
    auto func = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        return inputs[0];
    };
    auto op = std::make_shared<Operation>(func, std::vector<int>{}, "TestOp");
    OperationManager& manager = OperationManager::getInstance();
    manager.registerOperation("TestOp", op);
    auto retrievedOp = manager.getOperation("TestOp");
    EXPECT_EQ(retrievedOp->getName(), "TestOp");
    manager.removeOperation("TestOp");
}

TEST(OperationManagerTest, RegisterExistingOperation) {
    auto func = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        return inputs[0];
    };
    auto op = std::make_shared<Operation>(func, std::vector<int>{}, "TestOp");
    OperationManager& manager = OperationManager::getInstance();
    manager.registerOperation("TestOp", op);
    EXPECT_THROW({
        manager.registerOperation("TestOp", op);
    }, std::runtime_error);
    manager.removeOperation("TestOp");
}

TEST(OperationManagerTest, RemoveOperation) {
    auto func = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        return inputs[0];
    };
    auto op = std::make_shared<Operation>(func, std::vector<int>{}, "TestOp");
    OperationManager& manager = OperationManager::getInstance();
    manager.registerOperation("TestOp", op);
    manager.removeOperation("TestOp");
    EXPECT_THROW({
        manager.getOperation("TestOp");
    }, std::runtime_error);
}

TEST(OperationManagerTest, UpdateOperation) {
    auto func1 = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        return inputs[0];
    };
    auto func2 = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        return inputs[0] + " Updated";
    };
    auto op1 = std::make_shared<Operation>(func1, std::vector<int>{}, "TestOp");
    auto op2 = std::make_shared<Operation>(func2, std::vector<int>{}, "TestOp");
    OperationManager& manager = OperationManager::getInstance();
    manager.registerOperation("TestOp", op1);
    manager.updateOperation("TestOp", op2);
    auto retrievedOp = manager.getOperation("TestOp");
    EXPECT_EQ(retrievedOp->compute({"Input"}), "Input Updated");
    manager.removeOperation("TestOp");
}

TEST(OperationManagerTest, UpdateNonExistingOperation) {
    auto func = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        return inputs[0];
    };
    auto op = std::make_shared<Operation>(func, std::vector<int>{}, "TestOp");
    OperationManager& manager = OperationManager::getInstance();
    EXPECT_THROW({
        manager.updateOperation("NonExistingOp", op);
    }, std::runtime_error);
}

TEST(OperationManagerTest, ListOperations) {
    OperationManager& manager = OperationManager::getInstance();
    auto initialOps = manager.listOperations();
    size_t initialSize = initialOps.size();

    auto func = [](const std::vector<std::string>& inputs, const std::vector<int>& params) {
        return inputs[0];
    };
    auto op = std::make_shared<Operation>(func, std::vector<int>{}, "TestOp");
    manager.registerOperation("TestOp", op);

    auto ops = manager.listOperations();
    EXPECT_EQ(ops.size(), initialSize + 1);
    EXPECT_NE(std::find(ops.begin(), ops.end(), "TestOp"), ops.end());

    manager.removeOperation("TestOp");
}
