#pragma once
#include <string>
#include <map>


namespace k_mer{
    int kmer_count(std::string kmer, std::string sequence);
    int c_kmer_count(char* kmer, char* sequence);
    std::map<std::string, int> occurred_kmers(int k, std::string sequence);
    std::map<char*, int> c_occurred_kmers(int k, char* sequence);
    char** all_k_mers(int k);
    char* slice(char* s, int i, int j);
    char* sslice(std::string s, int i, int j);
}
