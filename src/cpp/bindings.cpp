// bindings.cpp

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Node.h"
#include "Operation.h"
#include "OperationFactory.h"
#include "OperationRegistry.h"

namespace py = pybind11;

PYBIND11_MODULE(strgraph, m) {
    m.doc() = "String Graph Module";

    // 绑定 Node 类
    py::class_<Node, std::shared_ptr<Node>>(m, "Node")
        .def(py::init<const std::string&, std::shared_ptr<Operation>>(),
             py::arg("value"), py::arg("operation") = nullptr)
        .def("getString", &Node::getString)
        .def("setString", &Node::setString)
        .def("computeString", &Node::computeString)
        .def("validateString", &Node::validateString)
        .def("setOperation", (void (Node::*)(const std::shared_ptr<Operation>&)) &Node::setOperation)
        .def("printInfo", &Node::printInfo)
        .def("hasLoop", &Node::hasLoop);

    // 绑定 Operation 类
    py::class_<Operation, std::shared_ptr<Operation>>(m, "Operation")
        .def("getName", &Operation::getName)
        .def("compute", &Operation::compute)
        .def("printInfo", &Operation::printInfo);

    // 绑定 OperationFactory 类
    m.def("createOperation", &OperationFactory::createOperation,
          py::arg("name"),
          py::arg("inputs"),
          py::arg("func") = nullptr);

    // 绑定 OperationRegistry 类
    m.def("registerOperation", &OperationRegistry::registerOperation,
          py::arg("name"),
          py::arg("func"));

    m.def("getOperation", &OperationRegistry::getOperation,
          py::arg("name"));

    // 绑定预定义的操作，例如 Concat
    OperationRegistry::registerOperation("concat", [](const std::vector<std::shared_ptr<Node>>& inputs) -> std::string {
        if (inputs.size() < 2) {
            throw std::runtime_error("Concat operation requires at least two inputs.");
        }
        std::string result;
        for (const auto& node : inputs) {
            result += node->getString();
        }
        return result;
    });

    // 绑定预定义的操作，例如 Delete
    OperationRegistry::registerOperation("delete_first", [](const std::vector<std::shared_ptr<Node>>& inputs) -> std::string {
        if (inputs.empty()) {
            throw std::runtime_error("Delete operation requires at least one input.");
        }
        std::string original = inputs[0]->getString();
        if (!original.empty()) {
            return original.substr(1);
        }
        return original;
    });

    // 让用户可以在 Python 中定义新的操作函数
    py::class_<std::function<std::string(const std::vector<std::shared_ptr<Node>>&)> >(m, "OperationFunction");

    m.def("define_operation", [](const std::string& name, py::function pyFunc) {
        auto opFunc = [pyFunc](const std::vector<std::shared_ptr<Node>>& inputs) -> std::string {
            py::gil_scoped_acquire acquire; // 确保 GIL 被持有
            py::list pyInputs;
            for (const auto& node : inputs) {
                pyInputs.append(node);
            }
            py::object result = pyFunc(pyInputs);
            return result.cast<std::string>();
        };
        OperationRegistry::registerOperation(name, opFunc);
    });
}
