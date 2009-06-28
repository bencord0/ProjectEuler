/*
There are exactly ten ways of selecting three from
five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 5C3 = 10.

In general,nCr = 	n!/r!(n-r)!	,where r<=n, n! = n*(n-1)...3*2*1, and 0! = 1.

It is not until n = 23, that a value exceeds one-million:
23C10 = 1144066.

How many, not necessarily distinct, values of  nCr, for 1<n<100,
are greater than one-million?
*/
#include <stdio.h>
#include <gmp.h>
#include "Problem053.h"

unsigned long int nCr(unsigned long int n, unsigned long int r);

int Problem053() {
	int n, r;
	int count = 0;
	int val;

	for(n=1;n<100;n++) {
		for(r=1;r<n;r++) {
			val = nCr(n,r);
			if(val>1000000) {
				count++;
	}	}	}

	printf("%d", count);
	return 0;
}

unsigned long int nCr(unsigned long int n, unsigned long int r) {
	mpz_t a,b,c, answer;
	unsigned long int ret;
	mpz_init(answer);
	mpz_init(a);
	mpz_init(b);
	mpz_init(c);

	if(n>r) {
			mpz_fac_ui(a,n);
			mpz_fac_ui(b,r);
			mpz_fac_ui(c,n-r);
			mpz_mul(b,b,c);
			mpz_divexact(answer,a,b);
	} else {
		mpz_set_ui(answer,0);
	}

	ret = mpz_get_ui(answer);
	mpz_clear(answer);
	mpz_clear(a);
	mpz_clear(b);
	mpz_clear(c);
	return ret;
}
