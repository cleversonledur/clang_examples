# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/cleversonledur/ownCloud/CLEVERSON_DR/CLANG/clang-lib-example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cleversonledur/ownCloud/CLEVERSON_DR/CLANG/clang-lib-example

# Include any dependencies generated for this target.
include CMakeFiles/CIrewriter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CIrewriter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CIrewriter.dir/flags.make

CMakeFiles/CIrewriter.dir/CIrewriter.cpp.o: CMakeFiles/CIrewriter.dir/flags.make
CMakeFiles/CIrewriter.dir/CIrewriter.cpp.o: CIrewriter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cleversonledur/ownCloud/CLEVERSON_DR/CLANG/clang-lib-example/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CIrewriter.dir/CIrewriter.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CIrewriter.dir/CIrewriter.cpp.o -c /home/cleversonledur/ownCloud/CLEVERSON_DR/CLANG/clang-lib-example/CIrewriter.cpp

CMakeFiles/CIrewriter.dir/CIrewriter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CIrewriter.dir/CIrewriter.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cleversonledur/ownCloud/CLEVERSON_DR/CLANG/clang-lib-example/CIrewriter.cpp > CMakeFiles/CIrewriter.dir/CIrewriter.cpp.i

CMakeFiles/CIrewriter.dir/CIrewriter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CIrewriter.dir/CIrewriter.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cleversonledur/ownCloud/CLEVERSON_DR/CLANG/clang-lib-example/CIrewriter.cpp -o CMakeFiles/CIrewriter.dir/CIrewriter.cpp.s

CMakeFiles/CIrewriter.dir/CIrewriter.cpp.o.requires:

.PHONY : CMakeFiles/CIrewriter.dir/CIrewriter.cpp.o.requires

CMakeFiles/CIrewriter.dir/CIrewriter.cpp.o.provides: CMakeFiles/CIrewriter.dir/CIrewriter.cpp.o.requires
	$(MAKE) -f CMakeFiles/CIrewriter.dir/build.make CMakeFiles/CIrewriter.dir/CIrewriter.cpp.o.provides.build
.PHONY : CMakeFiles/CIrewriter.dir/CIrewriter.cpp.o.provides

CMakeFiles/CIrewriter.dir/CIrewriter.cpp.o.provides.build: CMakeFiles/CIrewriter.dir/CIrewriter.cpp.o


# Object files for target CIrewriter
CIrewriter_OBJECTS = \
"CMakeFiles/CIrewriter.dir/CIrewriter.cpp.o"

# External object files for target CIrewriter
CIrewriter_EXTERNAL_OBJECTS =

CIrewriter: CMakeFiles/CIrewriter.dir/CIrewriter.cpp.o
CIrewriter: CMakeFiles/CIrewriter.dir/build.make
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMX86AsmParser.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMBitReader.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMSupport.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMMC.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMOption.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMProfileData.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMX86Desc.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMMCDisassembler.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMX86AsmPrinter.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMX86Utils.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMX86Info.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMObject.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMBitReader.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMMCParser.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMMC.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMCore.a
CIrewriter: /usr/lib/llvm-3.8/lib/libLLVMSupport.a
CIrewriter: CMakeFiles/CIrewriter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cleversonledur/ownCloud/CLEVERSON_DR/CLANG/clang-lib-example/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CIrewriter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CIrewriter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CIrewriter.dir/build: CIrewriter

.PHONY : CMakeFiles/CIrewriter.dir/build

CMakeFiles/CIrewriter.dir/requires: CMakeFiles/CIrewriter.dir/CIrewriter.cpp.o.requires

.PHONY : CMakeFiles/CIrewriter.dir/requires

CMakeFiles/CIrewriter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CIrewriter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CIrewriter.dir/clean

CMakeFiles/CIrewriter.dir/depend:
	cd /home/cleversonledur/ownCloud/CLEVERSON_DR/CLANG/clang-lib-example && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cleversonledur/ownCloud/CLEVERSON_DR/CLANG/clang-lib-example /home/cleversonledur/ownCloud/CLEVERSON_DR/CLANG/clang-lib-example /home/cleversonledur/ownCloud/CLEVERSON_DR/CLANG/clang-lib-example /home/cleversonledur/ownCloud/CLEVERSON_DR/CLANG/clang-lib-example /home/cleversonledur/ownCloud/CLEVERSON_DR/CLANG/clang-lib-example/CMakeFiles/CIrewriter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CIrewriter.dir/depend

