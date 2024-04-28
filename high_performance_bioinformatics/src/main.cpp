#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include "../genome/src/parse_genome.h"
#include "../genome/src/k_mer.h"
#include "../genome/src/seq_io.h"

int main(int argc, char** argv){
    std::cout << "Bioinformatics" << std::endl;
	char *sequence = seq_io::read_sequence(argv[1]);
	std::string ssequence = sequence;
	std::map<char*, int> kmers = k_mer::c_occurred_kmers(11, sequence);
	for (std::map<char*, int>::iterator it = kmers.begin(); it != kmers.end(); ++it){
		std::cout << it->first << " " << it->second << std::endl;
	}
    return 0;
}
