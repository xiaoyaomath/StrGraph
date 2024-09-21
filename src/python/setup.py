from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import os
import pybind11

class CustomBuildExtCommand(build_ext):
    def run(self):
        # Ensure that the build directory exists
        if not os.path.exists(self.build_temp):
            os.makedirs(self.build_temp)
        # Create directories for each source file
        for ext in self.extensions:
            for source in ext.sources:
                # Get the directory of the source file relative to the current directory
                source_dir = os.path.dirname(os.path.abspath(source))
                relative_dir = os.path.relpath(source_dir, os.getcwd())
                build_dir = os.path.join(self.build_temp, relative_dir)
                if not os.path.exists(build_dir):
                    os.makedirs(build_dir)
        super().run()

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
    Extension(
        name='strgraph',  # Name of the Python module
        sources=cpp_sources,
        include_dirs=[
            cpp_dir,  # Include directory for header files
            pybind11.get_include(),  # pybind11 include directories
            pybind11.get_include(user=True)
        ],
        language='c++',
        # Add '-std=c++11' to compile and link arguments
        extra_compile_args=['-O3', '-std=c++11'],
        extra_link_args=['-std=c++11'],
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
    version='1.0.0',
    author='Your Name',
    author_email='your.email@example.com',
    description='A Python package to execute string operations using graph structure.',
    long_description=long_description,
    long_description_content_type='text/markdown',
    ext_modules=ext_modules,
    cmdclass={'build_ext': CustomBuildExtCommand},
    zip_safe=False,
    classifiers=[
        'Programming Language :: Python :: 3',
        'Programming Language :: C++',
        'Operating System :: OS Independent',
    ],
    python_requires='>=3.6',
)
