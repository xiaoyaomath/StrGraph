# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/build

# Include any dependencies generated for this target.
include CMakeFiles/strgraph.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/strgraph.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/strgraph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/strgraph.dir/flags.make

CMakeFiles/strgraph.dir/src/cpp/Node.cpp.o: CMakeFiles/strgraph.dir/flags.make
CMakeFiles/strgraph.dir/src/cpp/Node.cpp.o: /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/Node.cpp
CMakeFiles/strgraph.dir/src/cpp/Node.cpp.o: CMakeFiles/strgraph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/strgraph.dir/src/cpp/Node.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/strgraph.dir/src/cpp/Node.cpp.o -MF CMakeFiles/strgraph.dir/src/cpp/Node.cpp.o.d -o CMakeFiles/strgraph.dir/src/cpp/Node.cpp.o -c /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/Node.cpp

CMakeFiles/strgraph.dir/src/cpp/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/strgraph.dir/src/cpp/Node.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/Node.cpp > CMakeFiles/strgraph.dir/src/cpp/Node.cpp.i

CMakeFiles/strgraph.dir/src/cpp/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/strgraph.dir/src/cpp/Node.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/Node.cpp -o CMakeFiles/strgraph.dir/src/cpp/Node.cpp.s

CMakeFiles/strgraph.dir/src/cpp/NodeFactory.cpp.o: CMakeFiles/strgraph.dir/flags.make
CMakeFiles/strgraph.dir/src/cpp/NodeFactory.cpp.o: /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/NodeFactory.cpp
CMakeFiles/strgraph.dir/src/cpp/NodeFactory.cpp.o: CMakeFiles/strgraph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/strgraph.dir/src/cpp/NodeFactory.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/strgraph.dir/src/cpp/NodeFactory.cpp.o -MF CMakeFiles/strgraph.dir/src/cpp/NodeFactory.cpp.o.d -o CMakeFiles/strgraph.dir/src/cpp/NodeFactory.cpp.o -c /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/NodeFactory.cpp

CMakeFiles/strgraph.dir/src/cpp/NodeFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/strgraph.dir/src/cpp/NodeFactory.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/NodeFactory.cpp > CMakeFiles/strgraph.dir/src/cpp/NodeFactory.cpp.i

CMakeFiles/strgraph.dir/src/cpp/NodeFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/strgraph.dir/src/cpp/NodeFactory.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/NodeFactory.cpp -o CMakeFiles/strgraph.dir/src/cpp/NodeFactory.cpp.s

CMakeFiles/strgraph.dir/src/cpp/Operation.cpp.o: CMakeFiles/strgraph.dir/flags.make
CMakeFiles/strgraph.dir/src/cpp/Operation.cpp.o: /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/Operation.cpp
CMakeFiles/strgraph.dir/src/cpp/Operation.cpp.o: CMakeFiles/strgraph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/strgraph.dir/src/cpp/Operation.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/strgraph.dir/src/cpp/Operation.cpp.o -MF CMakeFiles/strgraph.dir/src/cpp/Operation.cpp.o.d -o CMakeFiles/strgraph.dir/src/cpp/Operation.cpp.o -c /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/Operation.cpp

CMakeFiles/strgraph.dir/src/cpp/Operation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/strgraph.dir/src/cpp/Operation.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/Operation.cpp > CMakeFiles/strgraph.dir/src/cpp/Operation.cpp.i

CMakeFiles/strgraph.dir/src/cpp/Operation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/strgraph.dir/src/cpp/Operation.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/Operation.cpp -o CMakeFiles/strgraph.dir/src/cpp/Operation.cpp.s

CMakeFiles/strgraph.dir/src/cpp/OperationList.cpp.o: CMakeFiles/strgraph.dir/flags.make
CMakeFiles/strgraph.dir/src/cpp/OperationList.cpp.o: /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/OperationList.cpp
CMakeFiles/strgraph.dir/src/cpp/OperationList.cpp.o: CMakeFiles/strgraph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/strgraph.dir/src/cpp/OperationList.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/strgraph.dir/src/cpp/OperationList.cpp.o -MF CMakeFiles/strgraph.dir/src/cpp/OperationList.cpp.o.d -o CMakeFiles/strgraph.dir/src/cpp/OperationList.cpp.o -c /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/OperationList.cpp

CMakeFiles/strgraph.dir/src/cpp/OperationList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/strgraph.dir/src/cpp/OperationList.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/OperationList.cpp > CMakeFiles/strgraph.dir/src/cpp/OperationList.cpp.i

CMakeFiles/strgraph.dir/src/cpp/OperationList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/strgraph.dir/src/cpp/OperationList.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/OperationList.cpp -o CMakeFiles/strgraph.dir/src/cpp/OperationList.cpp.s

CMakeFiles/strgraph.dir/src/cpp/OperationManager.cpp.o: CMakeFiles/strgraph.dir/flags.make
CMakeFiles/strgraph.dir/src/cpp/OperationManager.cpp.o: /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/OperationManager.cpp
CMakeFiles/strgraph.dir/src/cpp/OperationManager.cpp.o: CMakeFiles/strgraph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/strgraph.dir/src/cpp/OperationManager.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/strgraph.dir/src/cpp/OperationManager.cpp.o -MF CMakeFiles/strgraph.dir/src/cpp/OperationManager.cpp.o.d -o CMakeFiles/strgraph.dir/src/cpp/OperationManager.cpp.o -c /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/OperationManager.cpp

CMakeFiles/strgraph.dir/src/cpp/OperationManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/strgraph.dir/src/cpp/OperationManager.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/OperationManager.cpp > CMakeFiles/strgraph.dir/src/cpp/OperationManager.cpp.i

CMakeFiles/strgraph.dir/src/cpp/OperationManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/strgraph.dir/src/cpp/OperationManager.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/OperationManager.cpp -o CMakeFiles/strgraph.dir/src/cpp/OperationManager.cpp.s

CMakeFiles/strgraph.dir/src/cpp/bindings.cpp.o: CMakeFiles/strgraph.dir/flags.make
CMakeFiles/strgraph.dir/src/cpp/bindings.cpp.o: /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/bindings.cpp
CMakeFiles/strgraph.dir/src/cpp/bindings.cpp.o: CMakeFiles/strgraph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/strgraph.dir/src/cpp/bindings.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/strgraph.dir/src/cpp/bindings.cpp.o -MF CMakeFiles/strgraph.dir/src/cpp/bindings.cpp.o.d -o CMakeFiles/strgraph.dir/src/cpp/bindings.cpp.o -c /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/bindings.cpp

CMakeFiles/strgraph.dir/src/cpp/bindings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/strgraph.dir/src/cpp/bindings.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/bindings.cpp > CMakeFiles/strgraph.dir/src/cpp/bindings.cpp.i

CMakeFiles/strgraph.dir/src/cpp/bindings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/strgraph.dir/src/cpp/bindings.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/bindings.cpp -o CMakeFiles/strgraph.dir/src/cpp/bindings.cpp.s

# Object files for target strgraph
strgraph_OBJECTS = \
"CMakeFiles/strgraph.dir/src/cpp/Node.cpp.o" \
"CMakeFiles/strgraph.dir/src/cpp/NodeFactory.cpp.o" \
"CMakeFiles/strgraph.dir/src/cpp/Operation.cpp.o" \
"CMakeFiles/strgraph.dir/src/cpp/OperationList.cpp.o" \
"CMakeFiles/strgraph.dir/src/cpp/OperationManager.cpp.o" \
"CMakeFiles/strgraph.dir/src/cpp/bindings.cpp.o"

# External object files for target strgraph
strgraph_EXTERNAL_OBJECTS =

strgraph.cpython-310-darwin.so: CMakeFiles/strgraph.dir/src/cpp/Node.cpp.o
strgraph.cpython-310-darwin.so: CMakeFiles/strgraph.dir/src/cpp/NodeFactory.cpp.o
strgraph.cpython-310-darwin.so: CMakeFiles/strgraph.dir/src/cpp/Operation.cpp.o
strgraph.cpython-310-darwin.so: CMakeFiles/strgraph.dir/src/cpp/OperationList.cpp.o
strgraph.cpython-310-darwin.so: CMakeFiles/strgraph.dir/src/cpp/OperationManager.cpp.o
strgraph.cpython-310-darwin.so: CMakeFiles/strgraph.dir/src/cpp/bindings.cpp.o
strgraph.cpython-310-darwin.so: CMakeFiles/strgraph.dir/build.make
strgraph.cpython-310-darwin.so: /Users/xiaoyao/miniconda3/lib/libpython3.10.dylib
strgraph.cpython-310-darwin.so: /Users/xiaoyao/miniconda3/lib/libpython3.10.dylib
strgraph.cpython-310-darwin.so: CMakeFiles/strgraph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX shared module strgraph.cpython-310-darwin.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/strgraph.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/strgraph.dir/build: strgraph.cpython-310-darwin.so
.PHONY : CMakeFiles/strgraph.dir/build

CMakeFiles/strgraph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/strgraph.dir/cmake_clean.cmake
.PHONY : CMakeFiles/strgraph.dir/clean

CMakeFiles/strgraph.dir/depend:
	cd /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/build /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/build /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/build/CMakeFiles/strgraph.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/strgraph.dir/depend

