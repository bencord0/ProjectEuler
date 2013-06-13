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
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a^2 + b^2 = c^2
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

/**
 * This program is in 3 parts,
 *	Part1: Generate the set of all combinations of a,b and c.
 *	Part2: Test for Pythagorean triplet and the 1000 summation.
 *	Part3: Return the product a*b*c
 */
#include <stdio.h>
#include "Problem009.h"

int Problem009(void) {
	int a,b,c=0;

	/* Part1 ****************/
	int escapism = 0;	/* controls flow */

	for(a=1; a<500; a++){
		for(b=a+1;b<500;b++) {
			c = 1000 - (a+b);

	/* Part2 *******************/
			escapism = is_Pythagorean_triplet(a,b,c);
		if(escapism) goto end009;
		}
	}

end009:
	/* Part3 ****************/
	printf("%30d", a*b*c);
	return 0;
}

int is_Pythagorean_triplet(int a, int b, int c) {
	if( (a*a + b*b) == c*c) return 1;
	return 0;
}
