#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "Node.h"
#include "Operation.h"
#include "OperationManager.h"
#include "NodeFactory.h"
#include "OperationList.h"

namespace py = pybind11;

// Helper function to create an operation node
std::shared_ptr<Node> create_operation_node(const std::string& opName, const std::vector<std::shared_ptr<Node>>& inputNodes) {
    return NodeFactory::createOperationNode(opName, inputNodes);
}

// Helper to dynamically expose operations as Python functions
void expose_operations(py::module& m) {
    auto& manager = OperationManager::getInstance();
    auto operations = manager.listOperations();

    for (const auto& opName : operations) {
        // Use the operation's name directly as the Python function name
        std::string pythonFuncName = opName;  

        // Dynamically expose the function in Python using the operation's name
        m.def(pythonFuncName.c_str(), [opName](const std::vector<std::shared_ptr<Node>>& nodes, const std::vector<int>& params = {}) {
            auto operationNode = create_operation_node(opName, nodes);
            if (!params.empty()) {
                operationNode->updateOperationParams(params);
            }
            return operationNode;
        }, py::arg("nodes"), py::arg("params") = std::vector<int>{});


        // Expose the operation object directly in Python using the lower-case operation name + "_op"
        std::string opVarName = opName;
        std::transform(opVarName.begin(), opVarName.end(), opVarName.begin(), ::tolower);
        opVarName += "_op";

        // Get the operation and expose it as a Python variable
        m.attr(opVarName.c_str()) = manager.getOperation(opName);
    }
}


PYBIND11_MODULE(strgraph, m) {
    // Register operations first
    registerOperations();

    // Bind Operation class
    py::class_<Operation, std::shared_ptr<Operation>>(m, "Operation")
        .def(py::init<const std::function<std::string(const std::vector<std::string>&, const std::vector<int>&)>&, const std::vector<int>&, const std::string&>())
        .def("compute", &Operation::compute)
        .def("get_name", &Operation::getName)
        .def("print_info", &Operation::printInfo)
        .def("clone", &Operation::clone)
        .def("set_params", &Operation::setParams)
        .def("set_name", &Operation::setName)
        .def("set_func", &Operation::setFunc);

    // Bind Node class, now with the constructor exposed
    py::class_<Node, std::shared_ptr<Node>>(m, "Node")
        .def(py::init<const std::string&, std::shared_ptr<Operation>, const std::vector<std::shared_ptr<Node>>&>(),
            py::arg("value"), 
            py::arg("op") = nullptr, 
            py::arg("inputNodes") = std::vector<std::shared_ptr<Node>>())
        .def("string", &Node::getString)
        .def("input_nodes", &Node::getInputNodes)
        .def("set_string", &Node::setString)
        .def("set_input_nodes", &Node::setInputNodes)
        .def("set_operation", &Node::setOperation)
        .def("compute_string", &Node::computeString)
        .def("compute_graph", &Node::computeGraph)
        .def("print_info", &Node::printInfo)
        .def("update_operation_params", &Node::updateOperationParams)
        .def("print_graph", &Node::printGraph);

    // Bind NodeFactory class
    py::class_<NodeFactory>(m, "NodeFactory")
        .def_static("create_value_node", &NodeFactory::createValueNode)
        .def_static("create_operation_node", &NodeFactory::createOperationNode);
    
    // Bind OperationManager class
    py::class_<OperationManager, std::shared_ptr<OperationManager>>(m, "OperationManager")
        .def_static("get_instance", &OperationManager::getInstance, py::return_value_policy::reference)
        .def("get_operation", &OperationManager::getOperation)
        .def("register_operation", &OperationManager::registerOperation)
        .def("remove_operation", &OperationManager::removeOperation)
        .def("update_operation", &OperationManager::updateOperation)
        .def("list_operations", &OperationManager::listOperations);

    // Expose OperationManager's get_operation method as "Operation"
    m.def("Operations", [](const std::string& op_name) {
        return OperationManager::getInstance().getOperation(op_name);
    });

    // Expose the same OperationManager singleton instance
    m.attr("manager") = py::cast(&OperationManager::getInstance(), py::return_value_policy::reference);

    // Dynamically expose all registered operations as Python functions
    expose_operations(m);

    // List operations in the manager
    OperationManager::getInstance().listOperations();
}