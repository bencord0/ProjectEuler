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
Find the greatest product of five consecutive digits in the 1000-digit number.
*/
char thousand_digit_number[] =
"73167176531330624919225119674426574742355349194934\
96983520312774506326239578318016984801869478851843\
85861560789112949495459501737958331952853208805511\
12540698747158523863050715693290963295227443043557\
66896648950445244523161731856403098711121722383113\
62229893423380308135336276614282806444486645238749\
30358907296290491560440772390713810515859307960866\
70172427121883998797908792274921901699720888093776\
65727333001053367881220235421809751254540594752243\
52584907711670556013604839586446706324415722155397\
53697817977846174064955149290862569321978468622482\
83972241375657056057490261407972968652414535100474\
82166370484403199890008895243450658541227588666881\
16427171479924442928230863465674813919123162824586\
17866458359124566529476545682848912883142607690042\
24219022671055626321111109370544217506941658960408\
07198403850962455444362981230987879927244284909188\
84580156166097919133875499200524063689912560717606\
05886116467109405077541002256983155200055935729725\
71636269561882670428252483600823257530420752963450";

#include <stdio.h>
#include <stdlib.h>
#include "Problem008.h"

#define DATA008 "008.data"

int Problem008(void) {
	int digits[5];
	int i,j;
	int max_product = 0;
	char ish[2];

	ish[1] = '\0';

	for(i=0;i<1000-5;i++) {
		for(j=i;j<i+5;j++) {
			ish[0] = thousand_digit_number[j];
			digits[j-i] = atoi(ish);
		}

		if(five_product(digits) > max_product) {
			max_product = five_product(digits);
		}
	}

	printf("%30d", max_product);

	return 0;
}

int five_product(int digits[5]) {
	return digits[0] * digits[1] * digits[2] * digits[3] * digits[4];
}
