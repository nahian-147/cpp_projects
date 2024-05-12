#pragma once
#include <string>
#include <map>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"


namespace parallel{
	extern "C"{
    int count_primes(unsigned long long n);
	}
}
