# File: src/python/setup.py
from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext
import os

# Get the directory where setup.py is located
this_dir = os.path.abspath(os.path.dirname(__file__))

# Define the extension module with absolute paths
cpp_dir = os.path.abspath(os.path.join(this_dir, "../cpp"))
cpp_sources = [
    os.path.join(cpp_dir, "Node.cpp"),
    os.path.join(cpp_dir, "NodeFactory.cpp"),
    os.path.join(cpp_dir, "Operation.cpp"),
    os.path.join(cpp_dir, "OperationList.cpp"),
    os.path.join(cpp_dir, "OperationManager.cpp"),
    os.path.join(cpp_dir, "bindings.cpp"),
]

ext_modules = [
    Pybind11Extension(
        "strgraph",
        cpp_sources,
        include_dirs=[cpp_dir],  # Include directory for header files
        cxx_std=11,
    )
]

# Read the README file for the long description (optional)
long_description = ''
readme_path = os.path.join(this_dir, 'README.md')
if os.path.exists(readme_path):
    with open(readme_path, encoding='utf-8') as f:
        long_description = f.read()

# Configure the setup
setup(
    name='strgraph',
    version='1.0.3',
    author='Yao Xiao',
    author_email='xiaoyaoin1980@gmail.com',
    description='A Python package to execute string operations using graph structure.',
    long_description=long_description,
    long_description_content_type='text/markdown',
    ext_modules=ext_modules,
    cmdclass={'build_ext': build_ext},
    zip_safe=False,
    classifiers=[
        'Programming Language :: Python :: 3',
        'Programming Language :: C++',
        'Operating System :: OS Independent',
    ],
    python_requires='>=3.6',
)
