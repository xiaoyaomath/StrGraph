# StrGraph

## Introduction

StrGraphCpp is a graph-based computation system designed for efficient string manipulation. It models computations and data dependencies as a Directed Acyclic Graph (DAG), where nodes represent string values and edges represent operations between nodes. The graph structure is defined in Python, allowing users to create flexible string-processing pipelines, while the computationally heavy operations are efficiently handled by a C++ backend.

## Installation

To build and run StrGraphCpp, you will need Python 3.6 or higher, along with a C++11-compatible compiler. The package relies on pybind11 for creating Python bindings for the C++ code, and setuptools for building and distributing the package. You will also need CMake for managing the build process, and Python development headers (e.g., python3-dev for Linux or equivalent for your OS). On Linux, dependencies like python3-dev, cmake, and g++ can be installed via apt, while on macOS, tools like Python and CMake can be installed using brew. For Windows, you need Visual Studio with C++ tools and can install CMake and pybind11 via pip.

1. To install, download the source code to path/to/StrGraph.

2. Open a terminal and navigate to the src/python directory within the source code.

3. Install the package using pip "pip install ."

Ensure that the Python version used for installation is the same version you will use for running the package.

4. To verify the installation, open a Python environment and import the package: "import strgraph".

## Tutorial

See StrGraph/src/docs/Tutorial1.ipynb