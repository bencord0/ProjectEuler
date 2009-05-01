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
	for (outer = 999; outer > 800; outer--)	{

		for (inner = 999; inner > outer; inner--)	{
			product = inner * outer;
			if(palindromeTest(product))	{
				biggest = (biggest>product) ? biggest:product;
			}
		}
	}

	printf("%lu", biggest);

	return 0;
}


