#pragma once
#include <string>
#include <map>


namespace k{

    extern "C"{
        int random();
        bool is_prime(unsigned long long n);
        int count_primes(unsigned long long limit);
    }
    
}
