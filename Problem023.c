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

/*
Extra Observations:
*/
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "functions.h"

int isFrom2abundantNumbers(int n);
int find_nearest_abundant_number(const int n, int level);
int Problem023(void)	{
	int i, sum=0;
	int a,b;
	int level;

	for(i=15;i<28123;++i) {
		level = 1;
next_a:
		a = find_nearest_abundant_number(i/2, level);
		if(!a) break; /* check error code */
		b = i-a;

		if(chkPerfection(b)>0) {
			sum -= i;
		} else {
			++level;
			goto next_a;
		}
	}

	for(i=0; i<28123; i++) {
		sum += i;
	}

	printf("%d", sum);
	return 0;
}

int find_nearest_abundant_number(const int n, int level) {
	/* It might be possible to run this code in parallel */
	int i = n, j = n;

	while (i < 2*n || j > 0) {
		if(chkPerfection(++i)>0 && --level == 0) {
			return i;
		}
		if(chkPerfection(--j)>0 && level == 0) {
			return j;
		}
	}
	return 0;
}

/**
 * Iterating through all possible n works, but is quite slow
 */
int isFrom2abundantNumbers(int n) {
	int a,b;

	for(a=1,b=n-a; a<=n/2; ++a, --b) {
		if(chkPerfection(a) + chkPerfection(b) == 2) {
			return 1;
		}
	}

	return 0;
}
