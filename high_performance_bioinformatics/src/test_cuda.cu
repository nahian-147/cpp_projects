#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <cctype>
#include "cuGENOME/parallel.h"
#include <cuda_runtime.h>


int main( void ) {
    int c;
    int *dev_c;

    cudaMalloc( (void**)&dev_c, sizeof(int) );
    parallel::add<<<1,1>>>( 1, 7, dev_c );

    cudaMemcpy( &c, dev_c, sizeof(int), cudaMemcpyDeviceToHost );

    cudaFree( dev_c );
    std::cout << c << std::endl;

}