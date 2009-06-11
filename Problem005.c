/**
 * 2520 is the smallest number that can be divided by each of
 * the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest number that is evenly divisible by
 * all of the numbers from 1 to 20?
 */
#include <stdio.h>
#include <math.h>

int Problem005(void) {
	int k=20;
	double N=1.0;
	int i=0;
	int check=1;
	int limit= (int) sqrt(k);
	/* A list of primes */
	int p[] = {2,3,5,7,11,13,17,19,20};
	/* initial powers of corresponding primes */
	int a[] = {1,1,1,1, 1, 1, 1, 1, 0};

	for(i=0;p[i]<k;i++) {
		if(check) {
			if(p[i] <= limit) {
				a[i] = (int) floor( log10(k) / log10(p[i]) );
			} else {
				check=0;
			}
		}
		N *= pow(p[i],a[i]);
	}

	printf("%30.0f", N);
	return 0;
}
