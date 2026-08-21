#pragma once
#include <vector>
#include <algorithm>

#define BASE_SIEVE 1048576

// Base case
namespace ver1
{
    std::vector<size_t> eratosthenes(size_t n);

    // Sieving
    void sieve(std::vector<size_t> &primes, size_t &count, size_t low, size_t len, size_t step, size_t limit);

    // Prime finding (timed in seconds)
    size_t primes_st(size_t limit);
    size_t primes_mt(size_t limit, int threads);
}



/*
    -------------------------------
    Excluding the even numbers
    -------------------------------
*/

namespace ver2
{
    // Base case
    std::vector<size_t> eratosthenes(size_t n);

    // Sieving
    void sieve(std::vector<size_t> &primes, size_t &count, size_t low, size_t len, size_t step, size_t limit);

    // Prime finding (timed in seconds)
    size_t primes_st(size_t limit);
    size_t primes_mt(size_t limit, int threads);
}