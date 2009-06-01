/*
Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:
Triangle	 	Tn=n(n+1)/2	 	1, 3, 6, 10, 15, ...
Pentagonal	 	Pn=n(3n-1)/2	 	1, 5, 12, 22, 35, ...
Hexagonal	 	Hn=n(2n-1)	 	1, 6, 15, 28, 45, ...


It can be verified that T285 = P165 = H143 = 40755.

Find the next triangle number that is also pentagonal and hexagonal.
*/

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "Problem045.h"

int tri(int n) {
	return (n*(n+1))/2;}
int invtri(int T) {
	int n = -1 + (int)sqrt(1 + (8*T));
	n /= 2;

	if(tri(n) == T ) {
		return n;
	}
	return 0;
}
int pen(int n) {
	return (n*((3*n)-1))/2;}
int invpen(int P) {
	int n = 1 + sqrt(1 + (24 * P));
	n = n/6;

	if(pen(n) == P) {
		return n;
	}
	return 0;
}
int hex(int n) {
	return n*((2*n)-1);}
int invhex(int H) {
	int n = 1 + sqrt(1 + (8*H));
	n /= 4;

	if(hex(n) == H) {
		return n;
	}
	return 0;
}

int is_n_answer(int n);

int Problem045() {
	return 1;
}
int _Problem045() {
	int n = 40755 + 1; /* know n = integer */

	while(!is_n_answer(n)) {
		++n;
	}

	printf("%d",n);
	return 0;
}

int is_n_answer(int n) {
	int T = invtri(n);
	int P = invpen(n);
	int H = invhex(n);
	if(H&&P) printf("is_n_answer: n:%d T:%d P:%d H:%d\n", n, T,P,H);
	if(T && P && H) {
		return 1;
	}
	return 0;
}
