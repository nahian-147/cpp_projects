#include "primes.h"
#include <string>
#include <map>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstring>

int k::random(){
    return rand()%15;
}

bool k::is_prime(unsigned long long n){
    if (n < 2) return false;
    if (n == 2) return true;
    for (size_t i = 2; i*i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int k::count_primes(unsigned long long limit){
    int count = 0;
    for (size_t i = 2; i <= limit; i++){
        if (k::is_prime(i)) count++;
    }
    return count;
}
