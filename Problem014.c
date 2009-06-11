
/**
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n = n/2 (n is even)
 * n = 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 * 13 40 20 10 5 16 8 4 2 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
 * Although it has not been proved yet (Collatz Problem), it is thought that all
 * starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */
#include <stdio.h>
#include <stdlib.h>
#include "Problem014.h"

#define LOOKUP_SIZE 1000000

int Problem014(void) {
/**
 * For a speed-up, I'll try to implement this using lookup tables,
 * a simple implementation is an array.
 */

	unsigned long long int index, length;
	unsigned long long int longest_chain_index=0, longest_chain_length=0;

	/**
	 * Setup the hash
	 */
	lookup = malloc(sizeof(unsigned long long int) *LOOKUP_SIZE+1);
	for(index = 0; index<LOOKUP_SIZE; index++) {
		*(lookup+index) = 0;
	}
	*(lookup+1)=1;

	/**
	 * Fill the hash
	 * aka: for(index=1; index<MAX; index++)
	 */
	for(index = 1; index<LOOKUP_SIZE; index++) {
		length = Collatz_length(index);
		/* side effect to solve the problem */
		if(longest_chain_length<length) {

			longest_chain_length = length;
			longest_chain_index = index;
		}
	}

	printf("%30llu",longest_chain_index);

	/**
	 * Bomb the hashes
	 */
	free(lookup);

	return 0;
}

/**
 * This suppliment is used to help me figure out the problem.
 * It works but is slow.
 */
unsigned long long int Collatz_length(unsigned long long int const index) {
	unsigned long long int op, length;
	op = index;

	if(index < LOOKUP_SIZE && lookup[index]) {
		return lookup[index];
	}

	if (op == 1) {
		return 1;
	}

	if(op%2 == 1) /* odd */ {
		op = (3*op) + 1;
	} else /* even */ {
		op /= 2;
	}
	length = Collatz_length(op) +1;

	if(index<LOOKUP_SIZE) {
		lookup[index] = length;
	}

	return length;
}
