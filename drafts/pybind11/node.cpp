#include <pybind11/pybind11.h>

namespace py = pybind11;

// 定义 Node 类
class Node {
public:
    // 构造函数
    Node(int value) : value(value) {}

    // 获取值
    int get_value() const {
        return value;
    }

    // 设置值
    void set_value(int v) {
        value = v;
    }

private:
    int value;
};

// 定义 Python 模块
PYBIND11_MODULE(node, m) {
    py::class_<Node>(m, "Node")  // 定义 Node 类
        .def(py::init<int>())    // 绑定构造函数
        .def("get_value", &Node::get_value)  // 绑定 get_value 方法
        .def("set_value", &Node::set_value); // 绑定 set_value 方法
}