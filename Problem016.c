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
