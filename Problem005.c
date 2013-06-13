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
 * 2520 is the smallest number that can be divided by each of
 * the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest number that is evenly divisible by
 * all of the numbers from 1 to 20?
 */
#include <stdio.h>
#include <math.h>

int Problem005(void) {
	int k=20;
	double N=1.0;
	int i=0;
	int check=1;
	int limit= (int) sqrt(k);
	/* A list of primes */
	int p[] = {2,3,5,7,11,13,17,19,20};
	/* initial powers of corresponding primes */
	int a[] = {1,1,1,1, 1, 1, 1, 1, 0};

	for(i=0;p[i]<k;i++) {
		if(check) {
			if(p[i] <= limit) {
				a[i] = (int) floor( log10(k) / log10(p[i]) );
			} else {
				check=0;
			}
		}
		N *= pow(p[i],a[i]);
	}

	printf("%30.0f", N);
	return 0;
}
