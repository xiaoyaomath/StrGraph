#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <string>

class Example {
public:
    // 默认构造函数
    Example();

    // 带参数的构造函数
    Example(int value);

    // 成员函数
    void setValue(int value);
    int getValue() const;

    // 重载函数
    void display() const;
    void display(const std::string& prefix) const;

    // 静态成员函数
    static int staticMethod(int x);

private:
    int value;
};

#endif // EXAMPLE_H
