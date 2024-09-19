from setuptools import setup, Extension
import pybind11

ext_modules = [
    Extension(
        'strgraph',
        ['bindings.cpp', 'Node.cpp', 'Operation.cpp', 'OperationFactory.cpp', 'OperationRegistry.cpp'],
        include_dirs=[
            pybind11.get_include(),
            '.',  # 包含头文件的目录
        ],
        language='c++',
        extra_compile_args=['-std=c++11'],
    ),
]

setup(
    name='strgraph',
    version='0.1',
    author='Your Name',
    author_email='your.email@example.com',
    description='String Graph Module',
    ext_modules=ext_modules,
    install_requires=['pybind11'],
)
