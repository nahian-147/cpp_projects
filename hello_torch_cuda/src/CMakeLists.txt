cmake_minimum_required(VERSION 3.5)

project(custom-dataset)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "/home/nahian/libtorch_cuda/share/cmake/Torch")
find_package(Torch REQUIRED)
find_package(OpenCV REQUIRED COMPONENTS core imgproc imgcodecs)

message(STATUS "OpenCV include dirs: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")


include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} "custom-dataset.cpp")
target_link_libraries(${PROJECT_NAME} "${OpenCV_LIBS}")
target_link_libraries(${PROJECT_NAME} "${TORCH_LIBRARIES}")

configure_file("info.txt" "info.txt" COPYONLY)



##---WINDOWS-ONLY---##

if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET ${PROJECT_NAME}
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif (MSVC)
