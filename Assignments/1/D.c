#include <stdio.h>
#include <gmp.h>

int main() {
    mpz_t n;
    mpz_init(n);

    gmp_scanf("%Zd", n);

    unsigned long count = mpz_popcount(n);
    printf("%lu\n", count);

    mpz_clear(n);
    return 0;
}