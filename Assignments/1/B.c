#include <stdio.h>
#include <gmp.h>
#include <string.h>

void karatsuba(mpz_t result, mpz_t num1, mpz_t num2) {
    if (mpz_cmp_ui(num1, 10) < 0 || mpz_cmp_ui(num2, 10) < 0) {
        mpz_mul(result, num1, num2);
        return;
    }

    size_t n = mpz_sizeinbase(num1, 10);
    size_t m = n / 2;

    mpz_t a, b, c, d, ac, bd, ad_plus_bc, temp;
    mpz_inits(a, b, c, d, ac, bd, ad_plus_bc, temp, NULL);

    mpz_ui_pow_ui(temp, 10, m);
    mpz_tdiv_q(a, num1, temp);
    mpz_tdiv_r(b, num1, temp);
    mpz_tdiv_q(c, num2, temp);
    mpz_tdiv_r(d, num2, temp);

    karatsuba(ac, a, c);
    karatsuba(bd, b, d);
    mpz_add(temp, a, b);
    mpz_add(result, c, d);
    karatsuba(ad_plus_bc, temp, result);
    mpz_sub(ad_plus_bc, ad_plus_bc, ac);
    mpz_sub(ad_plus_bc, ad_plus_bc, bd);

    mpz_ui_pow_ui(temp, 10, 2*m);
    mpz_mul(ac, ac, temp);
    mpz_ui_pow_ui(temp, 10, m);
    mpz_mul(ad_plus_bc, ad_plus_bc, temp);
    mpz_add(temp, ac, ad_plus_bc);
    mpz_add(result, temp, bd);

    mpz_clears(a, b, c, d, ac, bd, ad_plus_bc, temp, NULL);
}

int main() {
    mpz_t num1, num2, result;
    mpz_inits(num1, num2, result, NULL);

    gmp_scanf("%Zd", num1);
    gmp_scanf("%Zd", num2);

    karatsuba(result, num1, num2);
    gmp_printf("%Zd\n", result);

    mpz_clears(num1, num2, result, NULL);
    return 0;
}