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

void print_strand(char *seq, unsigned long long int seq_len){
    printf("Size of strand = %llu\n", str_size(seq));
    for(unsigned long long int k = 0; k < 15; k++){
        printf("%c",seq[k]);
    }
    printf("....");
    for(unsigned long long int k = seq_len-15; k < seq_len; k++){
        printf("%c",seq[k]);
    }
    printf("\n");
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

  int chunk_size = 10240;
  int n_chunks = (int)numElements/chunk_size + 1;
 
  for(int j = 0; j< n_chunks; j++){
    random_strand(h_A, chunk_size+1);
    print_strand(h_A, chunk_size);
    unsigned long long int strand_size = str_size(h_A);
    parallel::translate(h_A, h_C, chunk_size, size, strand_size);
    print_strand(h_C, chunk_size);
  }

  return 0;
}
