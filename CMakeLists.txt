cmake_minimum_required(VERSION 2.8.8)
project(CPP2C)

# Allow the user to override the install prefix.
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.
SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Now build our tools
add_executable(CIrewriter CIrewriter.cpp)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs x86asmparser bitreader support mc option profiledata)
message(STATUS "LLVM_LIBS: ${llvm_libs}")

target_link_libraries(CIrewriter
  clangFrontend
  clangSerialization
  clangDriver
  clangTooling
  clangParse
  clangSema
  clangAnalysis
  clangRewriteFrontend
  clangRewrite
  clangEdit
  clangAST
  clangLex
  clangBasic
  clangASTMatchers
  )

target_link_libraries(CIrewriter ${llvm_libs})

execute_process(COMMAND bash "-c" "llvm-config --cxxflags" OUTPUT_VARIABLE compile_flags OUTPUT_STRIP_TRAILING_WHITESPACE)
set_property(TARGET CIrewriter APPEND PROPERTY COMPILE_FLAGS "${compile_flags} -Wno-strict-aliasing")

install(TARGETS CIrewriter DESTINATION bin)
