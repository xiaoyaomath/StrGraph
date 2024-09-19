#include <pybind11/pybind11.h>
#include <pybind11/stl.h>  // 如果需要支持 STL 容器
#include "example.h"

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
    // 为类 Example 创建绑定
    py::class_<Example>(m, "Example")
        // 构造函数
        .def(py::init<>())              // 绑定默认构造函数
        .def(py::init<int>())           // 绑定带参数的构造函数

        // 成员函数
        .def("set_value", &Example::setValue)
        .def("get_value", &Example::getValue)

        // 属性（使用 getter 和 setter）
        .def_property("value", &Example::getValue, &Example::setValue)

        // 重载函数
        .def("display", py::overload_cast<>(&Example::display, py::const_))
        .def("display", py::overload_cast<const std::string&>(&Example::display, py::const_))

        // 静态成员函数
        .def_static("static_method", &Example::staticMethod);
}
