#include "seq_io.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <map>


char* seq_io::read_sequence_from_filepointer(FILE *fptr){
    char ch;
    std::vector<char> sequence_vector;
    char* sequence_flattened;

    if (NULL == fptr) {
        printf("file can't be opened \n");
    }
  
    while (!feof(fptr)) {
        ch = fgetc(fptr);
        sequence_vector.push_back(ch);
    }
    fclose(fptr);
    sequence_flattened = (char*)malloc((sequence_vector.size()+1)*sizeof(char));
    int j = 0;
    for(int i=0; i<sequence_vector.size(); i++){
        if(sequence_vector[i] != '\n')
            sequence_flattened[j++] = sequence_vector[i];
    }
    sequence_flattened[j] = '\0';
    sequence_vector.clear();
    return sequence_flattened;
}

char* seq_io::read_sequence(char* file_name){
    FILE* fptr;
    fptr = fopen(file_name, "r");
    char* sequence = seq_io::read_sequence_from_filepointer(fptr);
    return sequence;
}

