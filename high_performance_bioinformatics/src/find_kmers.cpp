#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include "genome/parse_genome.h"
#include "genome/k_mer.h"
#include "genome/seq_io.h"

int main(int argc, char** argv){
    std::cout << "Bioinformatics" << std::endl;
	char *sequence = seq_io::read_sequence(argv[2]);
	std::string ssequence = sequence;
	// std::map<char*, int> kmers = k_mer::c_occurred_kmers(atoi(argv[1]), sequence);
	// for (std::map<char*, int>::iterator it = kmers.begin(); it != kmers.end(); ++it){
	// 	std::cout << it->first << " " << it->second << std::endl;
	// }
	std::cout << "Length of Sequence " << strlen(sequence) << std::endl;
    std::map<std::string, int> skmers = k_mer::occurred_kmers(atoi(argv[1]), ssequence);
	for (std::map<std::string, int>::iterator it = skmers.begin(); it != skmers.end(); ++it){
		std::cout << it->first << " " << it->second << std::endl;
	}
    return 0;
}