#include <iostream>
#include "cuk/parallel.cuh"


int main(){

    std::cout << parallel::count_primes(10000000) << std::endl; 
}
