/**
 * 2520 is the smallest number that can be divided by each of
 * the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest number that is evenly divisible by
 * all of the numbers from 1 to 20?
 */
#include <stdio.h>
#include <gmp.h>
#include <limits.h>
#define LIMIT 20

int Problem005(void) {
	mpz_t suspect, test;
	mpz_init(suspect); mpz_init(test);
	
	for(mpz_set_str(suspect,"230000000", 10); mpz_cmp_ui(suspect,INT_MAX)<0; mpz_add_ui(suspect,suspect,1)) {

		for(mpz_set_ui(test,2); mpz_cmp(suspect, test) >0 && mpz_cmp_ui(test,LIMIT+1)<0 ; mpz_add_ui(test,test,1)) {

			/* elimnate useless suspects, */
			
			if(mpz_divisible_p(suspect,test)) {
				if(!mpz_cmp_ui(test,LIMIT)) {
					gmp_printf("%Zd", suspect);
					mpz_clear(suspect);mpz_clear(test);
					return 0;
				}
				continue;
			} else {
				break;
			}
		}
	}

	mpz_clear(suspect);mpz_clear(test);
	return 1;
}

