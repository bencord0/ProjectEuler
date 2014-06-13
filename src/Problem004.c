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
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 * 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
#include "functions.h"

int Problem004(void) {
	unsigned long int inner, outer, product;
	unsigned long int biggest=0;
	for (outer = 999; outer > 0; outer--)	{

		for (inner = 999; inner > outer; inner--)	{
			product = inner * outer;
			if(palindromeTest(product))	{
				biggest = (product>biggest) ? product:biggest;
			}
		}
	}

	printf("%30lu", biggest);

	return 0;
}


