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
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
int Problem016() {
	unsigned int i, sum;
	size_t size;
	char *buf;
	char ish[2];
	mpz_t a;
	mpz_init(a);

	ish[1] = '\0';

	mpz_ui_pow_ui(a, 2, 1000);

/*	gmp_printf("%Zd\n", a);*/
	size = mpz_sizeinbase(a, 10) + 1;
	buf = malloc(size);
	mpz_get_str(buf, 10, a);

	for(i=0,sum=0;i<size;i++) {
		ish[0] = buf[i];
		sum += atoi(ish);
	}

	printf("%30d", sum);

	mpz_clear(a);

	return 0;
}
