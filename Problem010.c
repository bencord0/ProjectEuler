
/**
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

#define true 1
#define false 0

int Problem010(void) {
	unsigned long int const limit = 2000000 ; /* prime upper bound */
	unsigned long int search_lim = (unsigned long int) floor(sqrt(limit));
	unsigned long int i,j;
	mpz_t sum;
	int *sieve;

	mpz_init(sum);
	sieve = malloc(sizeof(int) *  (limit+1));

	/* Assume all numbers are prime,
	 * then sieve out the composite ones
	 */
	for(i=0; i<limit; i++) {
		sieve[i]=true;
	}

	/* zero and 1 are not prime */
	sieve[0] = sieve[1] = false;

	for(i=2; i <= search_lim; i++) {
		if(sieve[i]) {

			/* this is prime, let's bomb the multiples  */
			for(j=i+i;j<limit;j+=i) {
				sieve[j] = false;
			}
		}
	}

	/* find primes and add */
	for(i=1;i<limit;i++) {
		if(sieve[i]) {
			mpz_add_ui(sum,sum,i);
		}
	}

	gmp_printf("%Zd", sum);
	mpz_clear(sum);
	free(sieve);
	return 0;
}
