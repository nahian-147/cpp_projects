#include <iostream>
#include <cctype>
#include "parse_genome.h"


bool genome_parser::is_genome(std::string seq){
    std::cout << "Sequence length = " << seq.length() << std::endl;
    for (int i=0; i<seq.length(); i++){
        char cursor = tolower(seq[i]);
        if (cursor!='a' && cursor!='c' && cursor!='g' && cursor!='t'){
            return false;
        }
    }
    return true;
}


std::string genome_parser::filter_seq(std::string seq){
    std::string filtered_seq = "";
    for (int i=0; i<seq.length(); i++){
        char cursor = tolower(seq[i]);
        if (cursor=='a' || cursor=='c' || cursor=='g' || cursor=='t'){
            filtered_seq += seq[i];
        }
    }
    return filtered_seq;
}
