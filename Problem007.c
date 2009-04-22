/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?
*/

#include <stdio.h>
#include <gmp.h>

int Problem007(void) {
	unsigned long const int max = 10001;
	unsigned long int counter;
	mpz_t prime;
	mpz_init_set_ui(prime, 1);
	
	for(counter = 0; counter < max; counter++) {
		do{
			mpz_nextprime(prime,prime);
		}while(mpz_probab_prime_p(prime,20)<2);
	}
	
	gmp_printf("%Zd", prime);
	mpz_clear(prime);
	return 0;
}
