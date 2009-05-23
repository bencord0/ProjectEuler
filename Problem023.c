/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28,
which means that 28 is a perfect number.

A number whose proper divisors are less than the number is called deficient
and a number whose properdivisors exceed the number is called abundant.
As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
number that can be written as the sum of two abundant numbers is 24.

By mathematical analysis, it can be shown that all integers greater than 28123 can
be written as the sum of two abundant numbers. However, this upper limit cannot be
reduced any further by analysis even though it is known that the greatest number that
cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "functions.h"

enum {ABUNDANT_NUMBER_CAP = 28123};

int Problem023(void)	{

	int *abundant_array;
	int *from_two_abundants_array;
	int i,j;

	/**
	 * Setup array of abundant numbers.
	 * Abundant numbers are marked.
	 */
	abundant_array = malloc(sizeof(int) * ABUNDANT_NUMBER_CAP+1);
	for(i=0; i<ABUNDANT_NUMBER_CAP;++i) {
		abundant_array[i] = 0;
		if(chkPerfection(i)>0) {
			abundant_array[i] = 1;
		}
	}

	/**
	 * Numbers that can be made from two abundant numbers
	 * are marked.
	 */
	from_two_abundants_array = malloc(sizeof(int) * ABUNDANT_NUMBER_CAP+1);
	for(i=0;i<ABUNDANT_NUMBER_CAP;++i) from_two_abundants_array[i] = 0;
	for(i=1;i<ABUNDANT_NUMBER_CAP;++i) {
		for(j=i;j<ABUNDANT_NUMBER_CAP;++j) {
			if(abundant_array[i] && abundant_array[j]) {
				from_two_abundants_array[i+j] = 1;
			}
		}
	}

	j=0;
	for(i=0;i<ABUNDANT_NUMBER_CAP;++i)
		if(!from_two_abundants_array[i]) {
			j+=i;
		}

	printf("%d", j);

	free(abundant_array);
	free(from_two_abundants_array);
	return 0;
}
