#include "example.h"
#include <iostream>

// 默认构造函数
Example::Example() : value(0) {}

// 带参数的构造函数
Example::Example(int value) : value(value) {}

// 设置值
void Example::setValue(int value) {
    this->value = value;
}

// 获取值
int Example::getValue() const {
    return value;
}

// 无参数的 display 函数
void Example::display() const {
    std::cout << "Value: " << value << std::endl;
}

// 带前缀的 display 函数
void Example::display(const std::string& prefix) const {
    std::cout << prefix << value << std::endl;
}

// 静态成员函数
int Example::staticMethod(int x) {
    return x * x;
}
