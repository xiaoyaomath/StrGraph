#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Node.h"
#include "Operation.h"
#include "OperationManager.h"
#include "OperationList.h" 

namespace py = pybind11;

PYBIND11_MODULE(strgraph, m) {
    // 绑定 Operation 类
    py::class_<Operation, std::shared_ptr<Operation>>(m, "Operation")
        .def(py::init<const std::function<std::string(const std::vector<std::string>&)>&, const std::vector<int>&, const std::string&>())
        .def("compute", &Operation::compute)
        .def("get_name", &Operation::getName)
        .def("print_info", &Operation::printInfo)
        .def("clone", &Operation::clone)
        .def("set_params", &Operation::setParams);

    // 绑定 Node 类
    py::class_<Node, std::shared_ptr<Node>>(m, "Node")
        .def(py::init<const std::string&, std::shared_ptr<Operation>, const std::vector<std::shared_ptr<Node>>&>())
        .def("get_string", &Node::getString)
        .def("get_substring", &Node::getSubstring)
        .def("set_string", &Node::setString)
        .def("set_input_nodes", &Node::setInputNodes)
        .def("set_operation", &Node::setOperation)
        .def("compute_string", &Node::computeString)
        .def("print_info", &Node::printInfo)
        .def("update_operation_params", &Node::updateOperationParams);

    // 绑定 OperationManager 类
    py::class_<OperationManager, std::shared_ptr<OperationManager>>(m, "OperationManager")
        .def_static("get_instance", &OperationManager::getInstance, py::return_value_policy::reference)
        .def("get_operation", &OperationManager::getOperation)
        .def("register_operation", &OperationManager::registerOperation)
        .def("remove_operation", &OperationManager::removeOperation)
        .def("update_operation", &OperationManager::updateOperation)
        .def("list_operations", &OperationManager::listOperations);

    // 绑定 registerOperations 函数
    m.def("register_operations", &registerOperations);  // 确保这个函数已经声明并可用
}
