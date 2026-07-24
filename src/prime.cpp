#include "prime.h"

#include <chrono>
#include <cstddef>
#include <thread>

// Base case
std::vector<size_t> eratosthenes(size_t n)
{
    std::vector<unsingned char> sieve(n >> 3, 0xff);
    unsigned char mask[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
    size_t i, j;
    for (i = 2; i * i < n; i++)
    {
        if (sieve[i >> 3] & mask[i & 7])
        {
            for (j = i * i; j < n; j += i)
                sieve[j >> 3] ^= mask[j & 7];
        }
    }

    std::vector<size_t> primes;
    for (i = 2; i < n; i++)
    {
        if (sieve[i >> 3] & mask[i & 7])
            primes.push_back(i);
    }
    return primes;
}

// Sieving
size_t sieve(std::vector<size_t> &primes, size_t low, size_t high);

// Prime finding (timed in seconds)
size_t primes_st(int seconds);
size_t primes_mt(int seconds, int threads);
