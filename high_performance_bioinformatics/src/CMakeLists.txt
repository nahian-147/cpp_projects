cmake_minimum_required(VERSION 3.13)

project(high_performance_bioinformatics LANGUAGES CXX CUDA)
enable_language(CUDA CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(high_performance_bioinformatics main.cpp)
target_link_libraries(high_performance_bioinformatics genome)

add_executable(find_kmers find_kmers.cpp)
target_link_libraries(find_kmers genome)

add_executable(test_str_cuda test_str_cuda.cu)
target_link_libraries(test_str_cuda cuGENOME)

add_executable(test_cuda_lib test_cuda_lib.cpp)
target_link_libraries(test_cuda_lib cuGENOME)

install(TARGETS find_kmers DESTINATION bin)
install(TARGETS test_cuda_lib DESTINATION bin)

# sudo ldconfig