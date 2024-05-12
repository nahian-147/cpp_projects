#include "parallel.cuh"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <cctype>


__global__ void parallel::translate_kernel(const char *A, char *C, unsigned long long int num_elements){
  
  unsigned long long int i = blockDim.x * blockIdx.x + threadIdx.x;
  
  if (i < num_elements){
  switch (A[i]){
    case 'A':
      C[i] = 'T';
      break;

    case 'T':
      C[i] = 'A';
      break;
                   
    case 'C':
      C[i] = 'G';
      break;
    
    case 'G':
      C[i] = 'C';
      break;               
    
    default:
      C[i] = ' ';
  }
  }
}

__global__ void parallel::rand_str_kernel( char *ptr, unsigned long long int num_elements ) {

    unsigned long long int i = blockDim.x * blockIdx.x + threadIdx.x;
    if (i < num_elements){
        switch (ptr[i]){
            case 'A':
            ptr[i] = 'a';
            break;

            case 'T':
            ptr[i] = 't';
            break;
                        
            case 'C':
            ptr[i] = 'c';
            break;
            
            case 'G':
            ptr[i] = 'g';
            break;               
            
            default:
            ptr[i] = ' ';
        }
  }
    
}

__global__ void parallel::add( int a, int b, int *c ) {
    *c = a + b;
}


void parallel::translate(char *h_A, char *h_C, unsigned long long int numElements, size_t size, unsigned long long int strand_size){

  cudaError_t err = cudaSuccess;

  char *d_A = NULL;
  err = cudaMalloc((void **)&d_A, size);

  char *d_C = NULL;
  err = cudaMalloc((void **)&d_C, size);

  printf("Copy input data from the host memory to the CUDA device\n");
  err = cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);

  int threadsPerBlock = 1024;
  unsigned long long int blocksPerGrid = (strand_size + threadsPerBlock - 1) / threadsPerBlock;
  printf("CUDA kernel launch with %llu blocks of %d threads\n", blocksPerGrid,
          threadsPerBlock);
  parallel::translate_kernel<<<blocksPerGrid,threadsPerBlock>>>(d_A, d_C, strand_size);
  // cudaDeviceSynchronize();

  cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);

  cudaFree(d_A);
  cudaFree(d_C);
}


char* parallel::rand_str( char *ptr, unsigned long long int num_elements ){
    cudaError_t err = cudaSuccess;

    char *d_ptr = NULL;
    size_t size = num_elements * sizeof(char);
    err = cudaMalloc((void **)&d_ptr, size);
    printf("Copy input data from the host memory to the CUDA device\n");
    err = cudaMemcpy(d_ptr, ptr, size, cudaMemcpyHostToDevice);

    parallel::rand_str_kernel<<<3,5>>>(ptr, num_elements);

    cudaMemcpy(ptr, d_ptr, size, cudaMemcpyDeviceToHost);
    cudaFree(d_ptr);
}