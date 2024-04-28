cmake_minimum_required(VERSION 3.27)

project(julia_set)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(glfw3 3.3 REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

enable_language(CUDA CXX)

add_executable(julia_gpu julia_gpu.cu cpu_bitmap.h book.h gl_helper.h)
target_link_libraries(julia_gpu ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} glfw)

add_executable(julia_cpu julia_cpu.cu cpu_bitmap.h book.h gl_helper.h)
target_link_libraries(julia_cpu ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} glfw)
