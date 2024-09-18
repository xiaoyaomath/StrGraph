#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "calculator.hpp"

TEST_CASE("Addition works", "[add]") {
    REQUIRE(add(2, 2) == 4);
    REQUIRE(add(0, 0) == 0);
    REQUIRE(add(-1, -1) == -2);
    // 一个可能会失败的测试用例
    REQUIRE(add(2, 2) == 5);
}