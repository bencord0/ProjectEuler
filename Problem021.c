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
	printf("%30d",sum);
	return 0;
}

/**
 * Prints the perfect numbers
 */
int Problem021_suppliment(void)	{
	int i=1;
	while(1)	{
		if(!chkPerfection(i) )	{
		printf("%30d\n",i);
		}
	i++;
	}
	return 0;
}
