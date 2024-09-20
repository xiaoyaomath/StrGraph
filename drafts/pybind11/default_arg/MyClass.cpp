#include <pybind11/pybind11.h>

namespace py = pybind11;

class MyClass {
public:
    MyClass(int x, int y = 42) : x_(x), y_(y) {}

    int get_x() const { return x_; }
    int get_y() const { return y_; }

private:
    int x_, y_;
};

PYBIND11_MODULE(my_module, m) {
    py::class_<MyClass>(m, "MyClass")
        .def(py::init<int, int>(), py::arg("x"), py::arg("y") = 42)  // 指定默认参数
        .def("get_x", &MyClass::get_x)
        .def("get_y", &MyClass::get_y);
}