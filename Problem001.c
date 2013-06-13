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
 *If we list all the natural numbers below 10 that are multiples of 3 or 5,
 *we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 *Find the sum of all the multiples of 3 or 5 below 1000.
 */
#include <stdio.h>

int Problem001(void)
{
	int sum = 0;
	int i;

	for (i = 1; i < 1000; i++)
	{
		if (!(i%3) ||!(i%5))
		{
			sum += i;
		}
	}
	printf("%30d",sum);
	return 0;
}
