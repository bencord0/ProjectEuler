/*
Here is the implementation of all my reusable functions in one easily referanced file.
Just #include "functions.h" and you have access to this vast library.
Remember to give this file, corresponding compiled object file, or this compiled as a library
to the compiler at link time.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
#include <math.h>
#include "functions.h"

/**
 * sum_divisors(n), the sum of the divisors of an integer n
 */
int sum_divisors(int n) {
	int sum=1, p=2, j;
	while(p*p<=n && n>1) {
		if(n%p==0) {
			j=p*p;
			n=n/p;
			while(!(n%p)) {
				j=j*p;
				n=n/p;
			}
			sum=sum*(j-1);
			sum=sum/(p-1);
		}
		if(p==2) {
			p=3;
		} else {
			p=p+2;
		}
	}
	if(n>1) {
		sum=sum*(n+1);
	}
	return sum;
}

int sum_proper_divisors(int n) {
	return sum_divisors(n) - n;
}

/**
 * If n<sum, n is a defficient number
 * n=sum, n is a perfect number
 * n>sum, n is an abundant number
 */
int chkPerfection(int n) {
	int d = sum_proper_divisors(n);
	if(d<n){return -1;}	/* difficient */
	if(d>n){return 1;}	/* abundant */
	return 0;	/* perfect */
}


int sumToN(int n)	{
	int sum = 0;
	for(;n>0;n--)	{
		sum += n;
	}
	return sum;
} /* Returns the sum of all integers from 1 to n */

/**
 * Returns non-zero if a is a palindrome
 */
int palindromeTest(unsigned long int a) {
	char *forward;
	char *backward;
	size_t size;
	mpz_t A;

	mpz_init_set_ui(A, a);
	size = mpz_sizeinbase(A, 10) + 1; /* for the sign and '\0' */
	forward = malloc(sizeof(char) * size);
	backward = malloc(sizeof(char) * size);

	if(size <= gmp_snprintf(forward, size, "%Zd", A)) {
		/*bad stuff happened*/
	}
	mpz_clear(A); /* Don't need it anymore */

	/* Now reverse the string, then compare */

	strcpy(backward, forward);
	backward = strrev(backward);

	if(strcmp(forward, backward)) {
		return 0;
	}

	return 1;
}

/**
 * Some compilers don't have this function
 * so I provide a version here.
 */
char *strrev(char *str) {
	char *p1, *p2, t;
	if (! str || ! *str)
		return str;
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
		t = *p1;
		*p1 = *p2;
		*p2 = t;
	}
	return str;
}/**/

int is_prime(unsigned long int num) {
	unsigned long int i;
	if(!num || num==1) return 0;

	for(i=2; i<sqrt(num); i++) {
		if(num % i)
			return 1;
		else break;
	}

	return 0;
}

/**
 * A triangular number sequence is formed by adding the natural numbers
 * mpz_triangular(rot,op) sets rop to the op'th triangular number.
 * t = n*(n+1)/2
 */
void mpz_triangular(mpz_t rop, mpz_t op) {
	mpz_t i;
	mpz_init(i);

	mpz_add_ui(i,op,1);
	mpz_mul(rop,op,i);
	mpz_divexact_ui(rop,rop,2);

	mpz_clear(i);
	return;
}

void mpz_triangular_ui(mpz_t rot, unsigned long int op) {
	mpz_t zop;
	mpz_init_set_ui(zop,op);
	mpz_triangular(rot,zop);
	mpz_clear(zop);
	return;
}
