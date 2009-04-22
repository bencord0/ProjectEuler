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

int addAllNumbers();
int solver();
int solver2();
int printAllAbundantNumbers(int n);
int madeFrom2Abundants(int val);
int findAbundant(int lower, int upper);

int Problem023(void)	{
	int answer;
	answer = solver2();
	printf("%d",answer);
	return 0;
}

int solver()	{
	int i,val = 0;
	for (i=28123;i>1;i--)	{
		if( !madeFrom2Abundants(i) )	{
			val += i;
		}
	}
	return val;
} /*outputs 4179870 */

int madeFrom2Abundants(int val)	{		/*OOO*/
	int i;
	for( i=(val-12); i>0; i--){
		if( sum_proper_divisors(i)>i )	{
			if( sum_proper_divisors(val - i)>(val - i) )	{
				return 1;
			}
		}
	}
	return 0;
}	/* Returns 1 if val is made of 2 abundant numbers, else 0.
	This makes no determination if there is more than one pair of
	abundants to make val*/

int printAllAbundantNumbers(int n)	{
	int i = 1;
	while( i <= n )	{
		if( sum_proper_divisors(i)>i )	{
			printf("%d\n",i);
		}
	i++;
	}
	return 0;
}

/* Alternative method:
	Above, madeFrom2Abundants() is call for every iteration, and has 2 further sub loops.
	This is way too slow.

	Instead, find all abundants, add all the pairs and parse etc.
*/

int solver2()	{ /* A rewrite */
	int sum = sumToN(28123),a,b,i;
	int abundantList[6965];
	int *abundant2list;
	mpz_t temp;

	for(i=0;i<6965;i++)	{
		abundantList[i] = findAbundant(i,28123);
	}
	
	mpz_init(temp);
	mpz_fac_ui(temp,28123);
	i=mpz_get_ui(temp);
	mpz_clear(temp);

	abundant2list = malloc(sizeof(int) * i);
	i=0;
	for(a=0;a<6965;a++)	{
		for(b=a;b<6965;b++)	{
			abundant2list[i++] = a+b;
		}
	}
	
	for(i=0;i<6965;i++)	{
		sum-=abundant2list[i];
	}
	
	free(abundant2list);
	return sum;
}

int findAbundant(int lower, int upper)	{
	for(lower++;lower<upper;lower++)	{
		if( sum_proper_divisors(lower)>lower )	{
			return lower;
		}
	}
	return 0;
} /*Finds an abundant number between lower and upper, returns 0 if none.*/

int nextAbundantNumber(int lower, int upper)	{
	while(lower<upper)	{
		lower++;
		if( sum_proper_divisors(lower)>lower )	{
			return lower;
		}
	}
	return 0;
}
