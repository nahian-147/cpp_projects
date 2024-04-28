#include <stdio.h>
#include <stdlib.h>
#include "genome/parallel.cuh"
#include "cuda_runtime.h"


unsigned long long int str_size(char* s){
  unsigned long long int n = 0;
  while(s[n] != '\0'){
    n++;
  }
  return n;
}

void random_strand(char* s, unsigned long long int n){
  const char A[5] = {'A', 'T', 'C', 'G'};
  for(unsigned long long int i=0; i<n-1; i++){
    *(s+i) = A[rand() % 4];
  }
  *(s+n-1) = '\0';
}

int main(int argc, char **argv){
  unsigned long long int numElements;
  if(argc >= 2){
    numElements = atoi(argv[1]);
  }else
    numElements = 3000000;
  
  size_t size = numElements * sizeof(char);

  char *h_A = (char *)malloc(size);

  char *h_C = (char *)malloc(size);

  random_strand(h_A, numElements);
  printf("Size of strand = %llu\n", str_size(h_A));
  for(unsigned long long int k = 0; k < 15; k++){
    printf("%c",h_A[k]);
  }
  printf("....");
  for(unsigned long long int k = numElements-15; k < numElements; k++){
    printf("%c",h_A[k]);
  }
  printf("\n");

  unsigned long long int strand_size = str_size(h_A);

  parallel::translate(h_A, h_C, numElements, size, strand_size);
  // cudaDeviceSynchronize();

  for(unsigned long long int k = 0; k < 15; k++){
    printf("%c",h_C[k]);
  }
  printf("....");
  for(unsigned long long int k = numElements-15; k < numElements; k++){
    printf("%c",h_C[k]);
  }
  printf("\n");


  // char* ptr;
  // random_strand(ptr, 15);
  // parallel::rand_str(ptr, 25);

  // for(int i=0; i<15; i++){
  //   printf("%c",ptr[i]);
  // }
  // printf("\n");

  return 0;
}
