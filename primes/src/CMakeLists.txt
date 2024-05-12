cmake_minimum_required(VERSION 3.27)

project(primes LANGUAGES CXX CUDA)
enable_language(CUDA CXX)
set(CMAKE_CXX_STANDARD 17)

add_library(primes SHARED primes.cpp)
set_target_properties(primes PROPERTIES PUBLIC_HEADER primes.h)
install(TARGETS primes DESTINATION lib
        PUBLIC_HEADER DESTINATION include/primes
)

add_library(cu_primes SHARED parallel_primes.cu)
set_target_properties(cu_primes PROPERTIES PUBLIC_HEADER parallel_primes.cuh)
install(TARGETS cu_primes DESTINATION lib
        PUBLIC_HEADER DESTINATION include/cu_primes
)

# set_target_properties(genome PROPERTIES PUBLIC_HEADER seq_io.h)
# install(TARGETS genome DESTINATION lib
#         PUBLIC_HEADER DESTINATION include/genome
# )

# add_library(cuGENOME SHARED parallel.cu)
# set_target_properties(cuGENOME PROPERTIES PUBLIC_HEADER parallel.cuh)
# install(TARGETS cuGENOME DESTINATION lib
#         PUBLIC_HEADER DESTINATION include/cuGENOME
# )

