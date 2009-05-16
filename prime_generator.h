#ifndef PRIME_GENERATOR_H
#define PRIME_GENERATOR_H

/* A simple struct to aid passing a set of options between functions */
struct opts {
	int count;
	char *arg[];
	/* Other opts here */
};

int generate_primes(unsigned long long int upper_bound/*, struct opts options*/);

#endif
