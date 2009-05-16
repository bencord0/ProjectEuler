#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "prime_generator.h"

/** SUPPLIMENTAL FUNCTION
 * Spits out a file with a list of prime numbers for quick referance for other programs.
 * Output is of the form ("%d:%d\n", n, nth_prime).
 * Optional:
 * 	use a flag to indicate strictness of prime checking.
 * 	use a flag to indicate which algorithm to use.
 */
int generate_primes(unsigned long long int upper_bound/*, struct opts options*/) {
	mpz_t p, q;
	FILE *prime_f;

	/* check if the file exists in the first place */
	prime_f = fopen("primes.txt", "r");
	if(prime_f != (FILE*) NULL) {
		fclose(prime_f);
		return 1;
	}
	prime_f = fopen("primes.txt", "w");
	if(prime_f == (FILE*) NULL) {
		/* we cant do much now */
		return 2;
	}
	mpz_init(p);
	mpz_init(q);
	/* some code to determine mode */
	/* generate primes */
	mpz_set_ui(p, 1);

	do {
		mpz_nextprime(q,p);
		gmp_fprintf(prime_f, "%Zd\n", q);
		mpz_set(p,q);
	} while (mpz_cmp_ui(p,upper_bound)<0);
	fclose(prime_f);
	mpz_clear(p);
	mpz_clear(q);
	return 0;
}
