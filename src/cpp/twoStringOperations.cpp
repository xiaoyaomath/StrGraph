// twoStringOperations.cpp
#include "twoStringOperations.h"

ConcatOperation::ConcatOperation(std::string* s1, std::string* s2)
    : StringOperationBase("concat", s1, s2) {}

void ConcatOperation::generate() {
    // 可以实现具体生成逻辑
}

std::string ConcatOperation::execute() {
    if (str1 && str2) {
        return *str1 + *str2;
    }
    return "";
}
