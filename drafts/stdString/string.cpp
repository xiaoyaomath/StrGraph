#include <iostream>
#include <string>

int main() {
    // 初始化字符串
    std::string str1 = "Hello";
    std::string str2 = "World";

    // 使用 operator+ 创建新字符串
    std::string result = str1 + str2;

    // 输出结果和原始字符串
    std::cout << "str1: " << str1 << std::endl;  // 输出 "Hello"
    std::cout << "str2: " << str2 << std::endl;  // 输出 "World"
    std::cout << "result (str1 + str2): " << result << std::endl;  // 输出 "HelloWorld"

    // 优化内存分配：使用 reserve 提前分配内存
    std::string optimizedResult;
    optimizedResult.reserve(str1.size() + str2.size());  // 预分配足够的内存

    // 使用 append 进行拼接
    optimizedResult.append(str1);
    optimizedResult.append(str2);

    // 输出优化拼接的结果
    std::cout << "optimizedResult (using reserve and append): " << optimizedResult << std::endl;  // 输出 "HelloWorld"

    return 0;
}
