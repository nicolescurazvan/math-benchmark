#include "prime.h"

#include <chrono>
#include <cstddef>
#include <thread>


// Base case (n must be multiple of 8)
std::vector<size_t> ver1::eratosthenes(size_t n)
{
    std::vector<size_t> primes;
    std::vector<bool> sieve(n, true);
    size_t i, j;
    for (i = 2; i * i < n; i++)
    {
        if (sieve[i])
        {
            for (j = i * i; j < n; j += i)
                sieve[j] = false;
        }
    }

    for (i = 2; i < n; i++)
    {
        if (sieve[i])
            primes.push_back(i);
    }
    return primes;
}

// Sieving (All numbers must be multiples of 8)
void ver1::sieve(std::vector<size_t> &primes, size_t &count, size_t low, size_t len, size_t step, size_t end)
{
    std::vector<bool> chunk(len);
    while (low < end)
    {
        std::fill(chunk.begin(), chunk.end(), true);
        size_t high = std::min(end, low + len);

        for (size_t p: primes)
        {
            size_t index = p - low % p;
            if (index == p)
                index = 0;
            
            for (; index < high - low; index += p)
                chunk[index] = false;
        }

        for (size_t i = 0; i < high - low; i++)
            count += chunk[i];
        
        low += step;
    }
}

// Prime finding (timed in seconds)
size_t ver1::primes_st(size_t limit)
{
    std::vector<size_t> primes = ver1::eratosthenes(BASE_SIEVE);
    size_t count = primes.size();
    ver1::sieve(primes, count, BASE_SIEVE, BASE_SIEVE, BASE_SIEVE, limit);
    return count;
}


size_t ver1::primes_mt(size_t limit, int threads)
{
    std::vector<size_t> primes = ver1::eratosthenes(BASE_SIEVE);
    size_t count = primes.size();
    
    std::vector<std::thread> workers;
    std::vector<size_t> cnt(threads, 0);
    for (size_t i = 0; i < threads; i++)
    {
        workers.emplace_back(ver1::sieve, std::ref(primes), std::ref(cnt[i]),\
            BASE_SIEVE * (i + 1), BASE_SIEVE, BASE_SIEVE * threads, limit);
    }
    for (std::thread& t: workers)
       t.join(); 
    
    for (size_t x: cnt)
        count += x;
    return count;
}