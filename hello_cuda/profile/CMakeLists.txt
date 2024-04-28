cmake_minimum_required(VERSION 3.27)

project(profile)

set(CMAKE_CXX_STANDARD 17)

enable_language(CUDA)

add_executable(profile profile.cu)

