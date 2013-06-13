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
If the numbers 1 to 5 are written out in words: one, two, three, four, five,
then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words,
how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two)
contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of
"and" when writing out numbers is in compliance with British usage.
*/

#include <stdio.h>
enum { one = 3, two = 3, three = 5, four = 4, five = 4, six  = 3,
 seven = 5, eight = 5, eigh = 4, nine = 4, ten = 3, eleven = 6, twelve = 6,
 twen = 4, thir = 4, teen=4, ty = 2, fif = 3,
 hundred = 7, thousand = 8
};

int one_ninetynine();
int somethinghundred_somethinghundredandninetynine(int something);
int Problem017() {
	int sum=0;

	sum += one_ninetynine();

	sum += somethinghundred_somethinghundredandninetynine(one);
	sum += somethinghundred_somethinghundredandninetynine(two);
	sum += somethinghundred_somethinghundredandninetynine(three);
	sum += somethinghundred_somethinghundredandninetynine(four);
	sum += somethinghundred_somethinghundredandninetynine(five);
	sum += somethinghundred_somethinghundredandninetynine(six);
	sum += somethinghundred_somethinghundredandninetynine(seven);
	sum += somethinghundred_somethinghundredandninetynine(eight);
	sum += somethinghundred_somethinghundredandninetynine(nine);

	sum += one + thousand;
	printf("%30d", sum);

	return 0;
}

int one_nine() {
	return 36;
}

int ten_nineteen() {
	int sum=0, i;
	sum += ten + eleven + twelve + thir + four + fif + six + seven + eigh + nine;
	for(i=13;i<=19;++i) {
		sum += teen;
	}
	return sum;
}

int something_somethingnine(int something) {
	int sum=0;
	sum += something * 10;
	sum += 56;
	return sum;
}

int one_ninetynine() {
	int sum=0;

	sum += one_nine();
	sum += ten_nineteen();

	sum += something_somethingnine(twen);
	sum += something_somethingnine(thir);
	sum += something_somethingnine(3);
	sum += something_somethingnine(fif);
	sum += something_somethingnine(six);
	sum += something_somethingnine(seven);
	sum += something_somethingnine(eigh);
	sum += something_somethingnine(nine);
	return sum;
}

int somethinghundred_somethinghundredandninetynine(int something) {
	int sum=0;

	sum += 100 * (something + hundred + 3);
	sum -= 3; /* and */
	sum += one_ninetynine();

	return sum;
}
