cmake_minimum_required(VERSION 3.4...3.18)
project(StrGraph)

# Find Python and pybind11 packages
find_package(Python REQUIRED COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)

# Add the library
add_library(strgraph MODULE
    src/cpp/Node.cpp
    src/cpp/NodeFactory.cpp
    src/cpp/Operation.cpp
    src/cpp/OperationList.cpp
    src/cpp/OperationManager.cpp
    src/cpp/bindings.cpp)

# Link pybind11 and Python
target_link_libraries(strgraph PRIVATE pybind11::module Python::Python)

# Set the properties for Python module
set_target_properties(strgraph PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}"
                                         SUFFIX "${PYTHON_MODULE_EXTENSION}")

# Specify the Python executable and include directories
target_include_directories(strgraph PRIVATE ${Python_INCLUDE_DIRS})
target_link_libraries(strgraph PRIVATE ${Python_LIBRARIES})
