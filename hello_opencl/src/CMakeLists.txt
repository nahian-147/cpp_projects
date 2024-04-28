cmake_minimum_required(VERSION 3.13)

project(hello_opencl)

add_executable(vector_add vector_add.cpp)

find_package(OpenCL REQUIRED)
target_link_libraries(vector_add OpenCL::OpenCL)
