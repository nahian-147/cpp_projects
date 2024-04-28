cmake_minimum_required(VERSION 3.13)

project(hello_glut)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(glfw3 3.3 REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

add_executable(hello_glut hello_glut.cpp glad.c)
target_link_libraries(hello_glut ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} glfw)

add_executable(basic_glut basic_glut.cpp)
target_link_libraries(basic_glut ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
