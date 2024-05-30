#include <stdio.h>
#include <gmp.h>

int main() {
    mpz_t n, m, inverse;
    mpz_inits(n, m, inverse, NULL);

    gmp_scanf("%Zd", n);
    gmp_scanf("%Zd", m);

    if (mpz_invert(inverse, n, m)) {
        gmp_printf("%Zd\n", inverse);
    } else {
        printf("No Inverse\n");
    }

    mpz_clears(n, m, inverse, NULL);
    return 0;
}