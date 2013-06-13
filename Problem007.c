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

	gmp_printf("%30Zd", prime);
	mpz_clear(prime);
	return 0;
}
