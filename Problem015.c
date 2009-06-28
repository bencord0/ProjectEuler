/**
 * Starting in the top left corner of a 2×2 grid, there are 6 routes
 * (without backtracking) to the bottom right corner.
 * How many routes are there through a 20×20 grid?
 */

#include <stdio.h>
#include <gmp.h>
#include "Problem015.h"
#include "functions.h"

int Problem015() {
	/**
	 * This problem reduces to the Central binomial coefficients.
	 * (2n)!/(n!)^2.
	 * Need the 20th
	 */
	mpz_t a, n;
	mpz_init(a);
	mpz_init(n);

	mpz_fac_ui(a, 40);
	mpz_fac_ui(n, 20);
	mpz_pow_ui(n, n, 2);

	mpz_divexact(n,a,n);

	gmp_printf("%30Zd", n);
	mpz_clear(a);
	mpz_clear(n);
	return 0;
}
