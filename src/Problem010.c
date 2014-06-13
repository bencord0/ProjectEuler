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

	gmp_printf("%30Zd", sum);
	mpz_clear(sum);
	free(sieve);
	return 0;
}
