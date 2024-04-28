#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <map>


namespace seq_io{
    char* read_sequence_from_filepointer(FILE *fptr);
    char* read_sequence(char* file_name);
}
