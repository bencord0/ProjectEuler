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
 * The series, 1^1 + 2^2 + ... + 10^10 = 10405071317
 * Find the last ten digits of the series, 1^1 + 1^2 + ... + 1000^1000.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
#include "Problem048.h"

int Problem048(void) {
	size_t size;
	int i;
	char *buf;
	mpz_t sum;
	mpz_t term;

	mpz_init_set_ui(sum,0);
	mpz_init(term);

	for(i=1;i<=1000;i++) {
		mpz_ui_pow_ui(term,i,i);
		mpz_add(sum,sum,term);
	}

	size = mpz_sizeinbase(sum,10) + 1;
	buf = malloc(size);
	mpz_get_str(buf, 10, sum);

	printf("                    ");
	printf("%s", buf+strlen(buf)-10);
	mpz_clear(sum);
	mpz_init(term);
	free(buf);
	return 0;
}
