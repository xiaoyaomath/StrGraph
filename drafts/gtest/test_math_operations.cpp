// test_math_operations.cpp
#include <gtest/gtest.h>
#include "math_operations.h"

TEST(MathTest, AddTest) {
    EXPECT_EQ(add(1, 2), 3);  // 测试1 + 2 是否等于 3
    EXPECT_EQ(add(-1, 1), 0); // 测试 -1 + 1 是否等于 0
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
