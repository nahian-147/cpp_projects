cmake_minimum_required(VERSION 3.27)

project(genome LANGUAGES CXX CUDA)
enable_language(CUDA CXX)
set(CMAKE_CXX_STANDARD 17)

add_library(genome SHARED parse_genome.cpp k_mer.cpp seq_io.cpp)
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

add_library(cuGENOME SHARED parallel.cu)
set_target_properties(cuGENOME PROPERTIES PUBLIC_HEADER parallel.cuh)
install(TARGETS cuGENOME DESTINATION lib
        PUBLIC_HEADER DESTINATION include/cuGENOME
)
