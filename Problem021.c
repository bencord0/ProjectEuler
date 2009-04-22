/*
Let d(n) be defined as the sum of proper divisors of n
(numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a != b, then a and b
are an amicable pair and each of a and b are called amicable numbers.
For example, the proper divisors of 220 are
1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
Evaluate the sum of all the amicable numbers under 10000.
*/
#include <stdio.h>
#include "functions.h"

int Problem021(void)	{
	int sum=0, a, b;
	for(a=2;a<10000;a++)	{
		b = sum_proper_divisors(a);
		if( sum_proper_divisors(b) == a && a<b )	{
				sum+=a+b;
			}
	}
	printf("%d",sum);
	return 0;
}

/**
 * Prints the perfect numbers
 */
int Problem021_suppliment(void)	{
	int i=1;
	while(1)	{
		if(!chkPerfection(i) )	{
		printf("%d\n",i);
		}
	i++;
	}
	return 0;
}
