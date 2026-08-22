#include <iostream>
#include <chrono>

#include <prime.h>
#include <euler.h>
#include <threadpool.h>

const char filler[] = "------------------------------------------\n";


int main()
{
    int threads = std::thread::hardware_concurrency();

    //------------------------------------------------

    size_t N[] = {1'000'000'000, 2'000'000'000, 3'000'000'000, 4'000'000'000, 6'000'000'000,\
        8'000'000'000, 12'000'000'000, 16'000'000'000, 24'000'000'000};
    
    std::cout << "Segmented sieve - single threaded\n"<< filler;
    for (size_t n: N)
    {
        auto start = std::chrono::steady_clock::now();
        size_t count = ver1::primes_st(n);
        auto end = std::chrono::steady_clock::now();
        auto t = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); 
        std::cout << "n = " << n << ": " << count << " primes found in ";
        std::cout << (double)t.count() / 1000 << " seconds\n";
    }
    std::cout << filler << "\n\n";
    

    std::cout << "Segmented sieve - single threaded, evens removed\n"<< filler;
    for (size_t n: N)
    {
        auto start = std::chrono::steady_clock::now();
        size_t count = ver2::primes_st(n);
        auto end = std::chrono::steady_clock::now();
        auto t = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); 
        std::cout << "n = " << n << ": " << count << " primes found in ";
        std::cout << (double)t.count() / 1000 << " seconds\n";
    }
    std::cout << filler << "\n\n";


    std::cout << "Segmented sieve - multithreaded\n"<< filler;
    for (size_t n: N)
    {
        auto start = std::chrono::steady_clock::now();
        size_t count = ver1::primes_mt(n, threads);
        auto end = std::chrono::steady_clock::now();
        auto t = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); 
        std::cout << "n = " << n << ": " << count << " primes found in ";
        std::cout << (double)t.count() / 1000 << " seconds\n";
    }
    std::cout << filler << "\n\n";


    std::cout << "Segmented sieve - multithreaded, evens removed\n"<< filler;
    for (size_t n: N)
    {
        auto start = std::chrono::steady_clock::now();
        size_t count = ver2::primes_mt(n, threads);
        auto end = std::chrono::steady_clock::now();
        auto t = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); 
        std::cout << "n = " << n << ": " << count << " primes found in ";
        std::cout << (double)t.count() / 1000 << " seconds\n";
    }
    std::cout << filler << "\n\n";


    //---------------------------------------------
    //---------------------------------------------

    /*
    size_t N2[] = {200, 300, 400, 500, 600, 700};
    std::cout << "Euler conjecture disprover - classical\n"<< filler;
    for (size_t n: N2)
    {
        auto start = std::chrono::steady_clock::now();
        size_t count = disprover(n);
        auto end = std::chrono::steady_clock::now();
        auto t = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); 
        std::cout << "n = " << n << ": " << count << " tuples found in ";
        std::cout << (double)t.count() / 1000 << " seconds\n";
    }
    std::cout << filler << "\n\n";
    */
    return 0;
}
