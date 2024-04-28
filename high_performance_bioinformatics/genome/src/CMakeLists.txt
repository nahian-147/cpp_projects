cmake_minimum_required(VERSION 3.27)

project(genome LANGUAGES CXX CUDA)
enable_language(CUDA CXX)
set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_CUDA_SEPARABLE_COMPILATION ON)
# set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(genome SHARED parse_genome.cpp k_mer.cpp seq_io.cpp parallel.cu parallel.cuh)
set_target_properties(genome PROPERTIES PUBLIC_HEADER parse_genome.h k_mer.h seq_io.h )
install(TARGETS genome DESTINATION lib
        PUBLIC_HEADER DESTINATION include/genome
)

set_target_properties(genome PROPERTIES PUBLIC_HEADER k_mer.h)
install(TARGETS genome DESTINATION lib
        PUBLIC_HEADER DESTINATION include/genome
)
set_target_properties(genome PROPERTIES PUBLIC_HEADER seq_io.h)
install(TARGETS genome DESTINATION lib
        PUBLIC_HEADER DESTINATION include/genome
)

set_target_properties(genome PROPERTIES PUBLIC_HEADER parallel.cuh )
install(TARGETS genome DESTINATION lib
        PUBLIC_HEADER DESTINATION include/genome
)
