# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/build

# Include any dependencies generated for this target.
include CMakeFiles/simple_demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simple_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simple_demo.dir/flags.make

CMakeFiles/simple_demo.dir/AST.cpp.o: CMakeFiles/simple_demo.dir/flags.make
CMakeFiles/simple_demo.dir/AST.cpp.o: ../AST.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simple_demo.dir/AST.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_demo.dir/AST.cpp.o -c /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/AST.cpp

CMakeFiles/simple_demo.dir/AST.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_demo.dir/AST.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/AST.cpp > CMakeFiles/simple_demo.dir/AST.cpp.i

CMakeFiles/simple_demo.dir/AST.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_demo.dir/AST.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/AST.cpp -o CMakeFiles/simple_demo.dir/AST.cpp.s

CMakeFiles/simple_demo.dir/IRGenerator.cpp.o: CMakeFiles/simple_demo.dir/flags.make
CMakeFiles/simple_demo.dir/IRGenerator.cpp.o: ../IRGenerator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/simple_demo.dir/IRGenerator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_demo.dir/IRGenerator.cpp.o -c /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/IRGenerator.cpp

CMakeFiles/simple_demo.dir/IRGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_demo.dir/IRGenerator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/IRGenerator.cpp > CMakeFiles/simple_demo.dir/IRGenerator.cpp.i

CMakeFiles/simple_demo.dir/IRGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_demo.dir/IRGenerator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/IRGenerator.cpp -o CMakeFiles/simple_demo.dir/IRGenerator.cpp.s

CMakeFiles/simple_demo.dir/lexer.cpp.o: CMakeFiles/simple_demo.dir/flags.make
CMakeFiles/simple_demo.dir/lexer.cpp.o: ../lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/simple_demo.dir/lexer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_demo.dir/lexer.cpp.o -c /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/lexer.cpp

CMakeFiles/simple_demo.dir/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_demo.dir/lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/lexer.cpp > CMakeFiles/simple_demo.dir/lexer.cpp.i

CMakeFiles/simple_demo.dir/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_demo.dir/lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/lexer.cpp -o CMakeFiles/simple_demo.dir/lexer.cpp.s

CMakeFiles/simple_demo.dir/main.cpp.o: CMakeFiles/simple_demo.dir/flags.make
CMakeFiles/simple_demo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/simple_demo.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_demo.dir/main.cpp.o -c /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/main.cpp

CMakeFiles/simple_demo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_demo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/main.cpp > CMakeFiles/simple_demo.dir/main.cpp.i

CMakeFiles/simple_demo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_demo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/main.cpp -o CMakeFiles/simple_demo.dir/main.cpp.s

CMakeFiles/simple_demo.dir/parser.cpp.o: CMakeFiles/simple_demo.dir/flags.make
CMakeFiles/simple_demo.dir/parser.cpp.o: ../parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/simple_demo.dir/parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_demo.dir/parser.cpp.o -c /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/parser.cpp

CMakeFiles/simple_demo.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_demo.dir/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/parser.cpp > CMakeFiles/simple_demo.dir/parser.cpp.i

CMakeFiles/simple_demo.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_demo.dir/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/parser.cpp -o CMakeFiles/simple_demo.dir/parser.cpp.s

# Object files for target simple_demo
simple_demo_OBJECTS = \
"CMakeFiles/simple_demo.dir/AST.cpp.o" \
"CMakeFiles/simple_demo.dir/IRGenerator.cpp.o" \
"CMakeFiles/simple_demo.dir/lexer.cpp.o" \
"CMakeFiles/simple_demo.dir/main.cpp.o" \
"CMakeFiles/simple_demo.dir/parser.cpp.o"

# External object files for target simple_demo
simple_demo_EXTERNAL_OBJECTS =

simple_demo: CMakeFiles/simple_demo.dir/AST.cpp.o
simple_demo: CMakeFiles/simple_demo.dir/IRGenerator.cpp.o
simple_demo: CMakeFiles/simple_demo.dir/lexer.cpp.o
simple_demo: CMakeFiles/simple_demo.dir/main.cpp.o
simple_demo: CMakeFiles/simple_demo.dir/parser.cpp.o
simple_demo: CMakeFiles/simple_demo.dir/build.make
simple_demo: /usr/lib/llvm-10/lib/libLLVMSupport.a
simple_demo: /usr/lib/llvm-10/lib/libLLVMCore.a
simple_demo: /usr/lib/llvm-10/lib/libLLVMIRReader.a
simple_demo: /usr/lib/llvm-10/lib/libLLVMAsmParser.a
simple_demo: /usr/lib/llvm-10/lib/libLLVMBitReader.a
simple_demo: /usr/lib/llvm-10/lib/libLLVMCore.a
simple_demo: /usr/lib/llvm-10/lib/libLLVMBinaryFormat.a
simple_demo: /usr/lib/llvm-10/lib/libLLVMRemarks.a
simple_demo: /usr/lib/llvm-10/lib/libLLVMBitstreamReader.a
simple_demo: /usr/lib/llvm-10/lib/libLLVMSupport.a
simple_demo: /usr/lib/llvm-10/lib/libLLVMDemangle.a
simple_demo: CMakeFiles/simple_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable simple_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simple_demo.dir/build: simple_demo

.PHONY : CMakeFiles/simple_demo.dir/build

CMakeFiles/simple_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simple_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simple_demo.dir/clean

CMakeFiles/simple_demo.dir/depend:
	cd /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/build /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/build /mnt/d/Programming/VScode/C/CompilePrinciple/Compiler/Compiler/simple_demo/build/CMakeFiles/simple_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simple_demo.dir/depend

