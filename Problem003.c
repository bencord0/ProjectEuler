/*
* Copyright 2013 Ben Cordero
*
* This file is part of my ProjectEuler implementations.
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <stdio.h>
#include <gmp.h>

int Problem003(void) {
	int check=1;
	mpz_t input;
	mpz_t suspected_prime_factor, largest_prime_factor;

	mpz_init_set_str(input, "600851475143", 0);
	mpz_init(suspected_prime_factor);
	mpz_init_set_ui(largest_prime_factor, 1);
	mpz_init_set_ui(suspected_prime_factor, 0);

	/**
	 * generate primes, remove the factors then test again
	 */
	while(check) {
		mpz_nextprime(suspected_prime_factor, suspected_prime_factor);

		if(mpz_cmp(input,suspected_prime_factor)<0) {
			check =0;
			printf("ERR");
		}
		/* Need to sure we are testing a prime number */
		if(mpz_probab_prime_p(suspected_prime_factor,10) == 2) {
		} else {
			continue;
		}


		if(mpz_divisible_p(input, suspected_prime_factor)) {
			mpz_remove(input, input, suspected_prime_factor);
			if(mpz_probab_prime_p(input,10)==2) {
				/**
				 * If input is prime, then either suspect
				 * or input is the answer
				 */
				if(mpz_cmp(suspected_prime_factor,input)>0){
					mpz_set(largest_prime_factor, suspected_prime_factor);
				}
				else {
					mpz_set(largest_prime_factor, input);
				}
				check = 0;
			}
		}

	}
	/*print largest_prime_factor*/
	gmp_printf("%30Zd", largest_prime_factor);

	mpz_clear(input);
	mpz_clear(suspected_prime_factor);
	mpz_clear(largest_prime_factor);
	return 0;
}

int Problem003_alt(void) {
	mpz_t input, test;

	mpz_init_set_str(input, "600851475143", 0);
	mpz_init_set(test, input);
	mpz_sub_ui(test,test,1);
/*	mpz_sqrt(test,input);*/

	while(!mpz_divisible_p(input, test)) {
		mpz_sub_ui(test, test, 1);
	}
	gmp_printf("%30Zd", test);

	mpz_clear(test);
	mpz_clear(input);

	return 0;
}
