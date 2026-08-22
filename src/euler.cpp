#include "euler.h"
#include <map>

// Fast function for a*a*a*a*a
inline size_t power5(size_t a)
{
    size_t b = a * a;
    return b * b * a;
}

// Disprove the Euler conjecture
size_t disprover(size_t n)
{
    size_t find = 0;
    size_t a, b, c, d, e;
    for (a = 1; a <= n; a++)
    {
        for (b = a; b <= n; b++)
        {
            for (c = b; c <= n; c++)
            {
                e = 1;
                for (d = c; d <= n; d++)
                {
                    size_t s = power5(a) + power5(b) + power5(c) + power5(d);
                    while (s > power5(e))
                        e++;
                    if (s == power5(e))
                        find++;
                }
            }
        }
    }
    return find;
}
