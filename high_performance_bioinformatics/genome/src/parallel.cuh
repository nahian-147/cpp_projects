#pragma once
#include <string>
#include <map>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"


namespace parallel{
    __global__ void translate_kernel(const char *A, char *C, unsigned long long int num_elements);
    void translate(char *h_A, char *h_C, unsigned long long int numElements, size_t size, unsigned long long int strand_size);
    __global__ void rand_str_kernel( char *ptr, unsigned long long int num_elements );
    void rand_str( char *ptr, unsigned long long int num_elements );
    __global__ void add( int a, int b, int *c );
}
