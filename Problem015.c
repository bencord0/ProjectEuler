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
