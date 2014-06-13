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
 * The sum of the squares of the first ten natural numbers is,
 * 1² + 2² + ... + 10² = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)² = 55² = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural numbers and
 * the square of the sum is 3025 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred natural numbers
 * and the square of the sum.
 */
#include <stdio.h>

int Problem006(void) {
	int input = 100;
	int i;
	int squareSum;
	int sumSquares;

	for( i=1, sumSquares=0, squareSum=0; i<=input; i++)	{
		sumSquares += i*i;
		squareSum += i;
	}

	squareSum = squareSum*squareSum;

	printf("%30d", (squareSum - sumSquares) );
	return 0;
}
