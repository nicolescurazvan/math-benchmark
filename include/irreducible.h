#pragma once
#include <cstdlib>

// Irreducible polynomials in Z[x]
size_t Z_irreducible(int n, size_t bound);
size_t Z_irreducible_mt(int n, size_t bound, int threads);

// Irreducible polynomials in Z2[x]
size_t Z2_irreducible(int n);
size_t Z2_irreducible_mt(int n, int threads);

// Irreducible polynomials in Z3[x]
size_t Z3_irreducible(int n);
size_t Z3_irreducible_mt(int n, int threads);
