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
	int N=1;
	int i=0;
	int check=1;
	int limit=sqrt(k);
	int p[] = {2,3,5,7,11,13,17,19};
	int a[] = {1,1,1,1, 1, 1, 1, 1};
	int pwr, j;

	while(p[i]<=k) {
		if(check) {

			if(p[i] <= limit) {
				a[i] = floor( log(k) / log(p[i]) );
			} else {
				check = 0;
			}
		}

		for(j=0,pwr=1;j<a[i];j++) {
			pwr *= p[i];
		}
		N = N * pwr;
		i++;
	}

	printf("%d",N);
	return 0;
}
