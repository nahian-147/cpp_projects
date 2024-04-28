#pragma once
#include <string>


namespace genome_parser{
    bool is_genome(std::string seq);

    std::string filter_seq(std::string seq);
}