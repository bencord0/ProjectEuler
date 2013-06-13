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
 * n! means n  (n  1)  ...  3  2  1
 *
 * Find the sum of the digits in the number 100!
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
int Problem020(void) {
	mpz_t fac;
	int sum, i, size;
	char *buf;
	char ish[2];

	ish[1] = '\0';
	mpz_init(fac);

	mpz_fac_ui(fac, 100);
	size = mpz_sizeinbase(fac,10) + 1;
	buf = malloc(sizeof(char) * (size));

	mpz_get_str(buf,10,fac);

	for(i=0,sum=0;i<size;i++) {
		ish[0] = *(buf+i);
		sum+=atoi(ish);
	}
	printf("%30d",sum);

	free(buf);
	mpz_clear(fac);
	return 0;
}
