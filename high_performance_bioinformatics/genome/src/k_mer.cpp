#include "k_mer.h"
#include <string>
#include <map>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstring>


void print_list_of_str(char** list_of_str, int n_str){
    for(int i=0; i<n_str; i++){
        std::cout << i+1 << ". " << list_of_str[i] << std::endl;
    }
}

char** k_mer::all_k_mers(int k){
    char alphabet[4] = {'a', 't', 'c', 'g'};
    if(k==1){
        char **mers;
        mers = (char**)malloc(4*sizeof(char*));
        for(int j=0; j<4; j++){
            mers[j] = (char*)malloc(2*sizeof(char));
            mers[j][0] = alphabet[j];
            mers[j][1] = '\0';
        }
        return mers;
    }
    else{
        char **mers;
        char **k_minus_one_mers;
        int n = pow(4,k-1);
        mers = (char**)malloc(4*n*sizeof(char*));
        k_minus_one_mers = k_mer::all_k_mers(k-1);
        int i=0;
        for(int t=0; t<n; t++){
            char* s = *(k_minus_one_mers + t);
            for(int j=0; j<4; j++){
                *(mers+i) = (char*)malloc((k+1)*sizeof(char));
                *(*(mers + i)) = alphabet[j];
                strcat(mers[i], s);
                i++;
            }
        }
        free(k_minus_one_mers);
        return mers;
    }
}


int find_occurance(char* k_mer, int k_mer_len, char* sequence, int sequence_len){
    int count = 0;
    for(int i=0; i<sequence_len-k_mer_len; i++){
        int temp = 0;
        for(int j=0; j<k_mer_len; j++){
            if(k_mer[j] != sequence[i+j]){
                temp++;
                break;
            }else{
                temp += 0;
            }
        }
        if(temp == 0){
            count++;
        }
    }
    return count;
}

char* k_mer::slice(char* s, int i, int j){
    if(j > i){
        int size = j-i+1;
        char* sub_s;
        sub_s = (char*)malloc(size*sizeof(char));
        for(int p=0; p<j-i; p++){
            sub_s[p] = s[i+p];
        }
        return sub_s;
    }else {
        return NULL;
    }
}

char* k_mer::sslice(std::string s, int i, int j){
    if(j > i){
        int size = j-i+1;
        char* sub_s;
        sub_s = (char*)malloc(size*sizeof(char));
        for(int p=0; p<j-i; p++){
            sub_s[p] = s[i+p];
        }
        return sub_s;
    }else {
        return NULL;
    }
}

int k_mer::kmer_count(std::string kmer, std::string sequence){
    int k = kmer.length();
    unsigned long sequence_size = sequence.length();
    int count = 0; 
    for (unsigned long i=0; i<sequence_size-k+1; i++){
        int tracker = 0;
        for (int j=0; j<k; j++){
            if (kmer[j] != sequence[i+j]){
                break;
            }else
                tracker++;
        }
        if (tracker==k){
            count++;
        }
    }
    return count;
}

int k_mer::c_kmer_count(char* kmer, char* sequence){
    int k = strlen(kmer);
    unsigned long sequence_size = strlen(sequence);
    int count = 0; 
    for (unsigned long i=0; i<sequence_size-k; i++){
        int tracker = 0;
        for (int j=0; j<k; j++){
            if (kmer[j] != sequence[i+j]){
                break;
            }else
                tracker++;
        }
        if (tracker==k){
            count++;
        }
    }
    return count;
}

std::map<char*, int> k_mer::c_occurred_kmers(int k, char* sequence){
    std::map<char*, int> kmer_map;
    char* kmer;
    for (int i=0; i<strlen(sequence)-k; i++){
        kmer = k_mer::slice(sequence, i, i+k);
        if (kmer_map.find(kmer) == kmer_map.end()){
            kmer_map[kmer] = k_mer::c_kmer_count(kmer, sequence);
        }
    }
    return kmer_map;
}

std::map<std::string, int> k_mer::occurred_kmers(int k, std::string sequence){
    std::map<std::string, int> kmer_map;
    char* kmer;
    std::string skmer;
    for (int i=0; i<sequence.length()-k; i++){
        kmer = k_mer::sslice(sequence, i, i+k);
        skmer = kmer;
        if (kmer_map.find(skmer) == kmer_map.end()){
            kmer_map[skmer] = k_mer::kmer_count(skmer, sequence);
        }
    }
    return kmer_map;
}
