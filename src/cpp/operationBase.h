//operationBase.h
#ifndef STRINGOPERATIONBASE_H
#define STRINGOPERATIONBASE_H

#include <string>
#include <iostream>

class StringOperationBase {
protected:
    std::string operation_name;
    std::string* str1;
    std::string* str2;  // only for operations with 2 string inputs
    bool is_single_input;  // true if only one string input

public:
    // 构造函数：用于单字符串操作
    StringOperationBase(const std::string& op_name, std::string* s1)
        : operation_name(op_name), str1(s1), str2(nullptr), is_single_input(true) {}

    // 构造函数：用于双字符串操作
    StringOperationBase(const std::string& op_name, std::string* s1, std::string* s2)
        : operation_name(op_name), str1(s1), str2(s2), is_single_input(false) {}

    virtual ~StringOperationBase() {}

    // 获取运算名称
    std::string getOperationName() const {
        return operation_name;
    }

    // 输出运算详细信息
    void printDetails() const {
        std::cout << "Operation: " << operation_name << std::endl;
        std::cout << "String 1: " << (str1 ? *str1 : "nullptr") << std::endl;
        if (!is_single_input && str2) {
            std::cout << "String 2: " << *str2 << std::endl;
        }
    }

    // 纯虚函数：生成操作
    virtual void generate() = 0;

    // 纯虚函数：执行操作
    virtual std::string execute() = 0;
};

#endif // STRINGOPERATIONBASE_H