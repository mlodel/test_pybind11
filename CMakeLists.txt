cmake_minimum_required(VERSION 3.4...3.18)
project(example)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

add_subdirectory(pybind11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin)

pybind11_add_module(example src/example.cpp)
pybind11_add_module(example_class src/example_class.cpp)
pybind11_add_module(interface src/main.cpp)