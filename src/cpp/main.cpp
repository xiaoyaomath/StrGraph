#include "Node.h"
#include "OperationList.cpp"

int main() {
    // 注册所有操作
    registerOperations();

    // 创建节点并设置操作
    Node node1("Hello, ");
    node1.setOperation("concat", {"World!"});
    std::cout << "Result: " << node1.computeString() << std::endl; // 输出: "Hello, World!"

    Node node2("  Hello  ");
    node2.setOperation("trim");
    std::cout << "Trimmed: " << node2.computeString() << std::endl; // 输出: "Hello"

    Node node3("abcdefg");
    node3.setOperation("slice", {"2", "3"});
    std::cout << "Sliced: " << node3.computeString() << std::endl; // 输出: "cde"

    return 0;
}
