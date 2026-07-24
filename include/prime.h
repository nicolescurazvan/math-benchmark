#include <vector>
#include <bitset>

#define BASE_SIEVE 1048576

// Base case
std::vector<size_t> eratosthenes(size_t n);

// Sieving
size_t sieve(std::vector<size_t> &primes, size_t low, size_t high);

// Prime finding (timed in seconds)
size_t primes_st(int seconds);
size_t primes_mt(int seconds, int threads);
