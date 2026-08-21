#include "prime.h"

#include <chrono>
#include <cstddef>
#include <thread>


// Base case (n must be multiple of 2)
std::vector<size_t> ver2::eratosthenes(size_t n)
{
    std::vector<size_t> primes;
    std::vector<bool> sieve(n, true);
    size_t i, j;
    for (i = 3; i * i < n; i += 2)
    {
        if (sieve[i])
        {
            for (j = i * i; j < n; j += 2 * i)
                sieve[j] = false;
        }
    }

    for (i = 3; i < n; i += 2)
    {
        if (sieve[i])
            primes.push_back(i);
    }
    return primes;
}

// Sieving (All numbers must be multiples of 2)
void ver2::sieve(std::vector<size_t> &primes, size_t &count, size_t low, size_t len, size_t step, size_t end)
{
    std::vector<bool> chunk(len);
    while (low < end)
    {
        std::fill(chunk.begin(), chunk.end(), true);
        size_t high = std::min(end, low + len);

        for (size_t p: primes)
        {
            size_t index = p - low % p;
            if (index % 2 == 0)
                index += p;
            
            for (; index < high - low; index += 2 * p)
                chunk[index] = false;
        }

        for (size_t i = 1; i < high - low; i += 2)
            count += chunk[i];
        
        low += step;
    }
}

// Prime finding (timed in seconds)
size_t ver2::primes_st(size_t limit)
{
    std::vector<size_t> primes = ver2::eratosthenes(BASE_SIEVE);
    size_t count = 1 + primes.size();
    ver2::sieve(primes, count, BASE_SIEVE, BASE_SIEVE, BASE_SIEVE, limit);
    return count;
}


size_t ver2::primes_mt(size_t limit, int threads);