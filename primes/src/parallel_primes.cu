#include "parallel_primes.cuh"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <cctype>
#include <cmath>
#include <cstdlib>


__global__ void is_divisible(int* is_d, int number){

  unsigned long long int i = blockDim.x * blockIdx.x + threadIdx.x;
  if ((i+2)*(i+2) <= number) {
    if (number%(i+2) == 0) is_d[i] = true;
    else is_d[i] = false;
  }else is_d[i] = false;
  
}


__device__ bool is_prime(unsigned long n){
  
  if (n < 2) return false;
  if (n == 2) return true;

  for (int i = 2; i*i <= n; i++){
    if (n % i == 0) return false;
  }
  
  return true;
  
}

__global__ void count_primes_kernel( int *collector, int chunk_size, int chunk_count, unsigned long long int limit ) {

  unsigned long long int i = blockDim.x * blockIdx.x + threadIdx.x;

  int local_count = 0;
  if (i < chunk_count){
    for (int k = i*chunk_size; k < (i+1)*chunk_size; k++){
      if (is_prime(k)) local_count++;
    }
  }else if (i == chunk_count && i*chunk_size <= limit){
    for (int k = i*chunk_size; k <= limit; k++){
      if (is_prime(k)) local_count++;
    }
  }
  collector[i] = local_count;
    
}

__global__ void count_primes_kernel_micro( int *collector, unsigned long long int limit ) {

  unsigned long long int i = blockDim.x * blockIdx.x + threadIdx.x;

  if (i <= limit){
    if (is_prime(i+1)) collector[i] = 1;
  }
    
}

int parallel::count_primes(unsigned long long n){

  int chunk_size = 100;
  int chunk_count = floor(n/chunk_size);
  // printf("Chunk count %d\n", chunk_count);

  size_t size = (chunk_count+1) * sizeof(int);
  int *collector_device = NULL;
  cudaMalloc((void **)&collector_device, size);

  int *collector_host = (int*) malloc(size);

  for (size_t i = 0; i < chunk_count+1; i++){
    collector_host[i] = 0;
  }
  

  // printf("Copy input data from the host memory to the CUDA device\n");
  cudaMemcpy(collector_device, collector_host, size, cudaMemcpyHostToDevice);

  int threadsPerBlock = 1024;
  unsigned long long int blocksPerGrid = (chunk_count + threadsPerBlock - 1) / threadsPerBlock;
  // printf("CUDA kernel launch with %llu blocks of %d threads\n", blocksPerGrid, threadsPerBlock);
  count_primes_kernel<<<blocksPerGrid,threadsPerBlock>>>(collector_device, chunk_size, chunk_count, n);

  cudaMemcpy(collector_host, collector_device, size, cudaMemcpyDeviceToHost);

  cudaFree(collector_device);

  int count = 0;
  for (size_t i = 0; i < chunk_count+1; i++){
    // printf("%d ",collector_host[i]);
    count += collector_host[i];
  }
  // printf("\n");

  free(collector_host);

  return count;
   
}
