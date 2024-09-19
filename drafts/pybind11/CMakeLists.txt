cmake_minimum_required(VERSION 3.4...3.18)
project(pybind11_example)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 寻找 Pybind11 包
find_package(pybind11 REQUIRED)

# 添加 Python 模块
pybind11_add_module(example bindings.cpp example.cpp)
