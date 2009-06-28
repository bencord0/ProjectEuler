#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <gmp.h>

int sum_divisors(int n);
int sum_proper_divisors(int n);
int chkPerfection(int n);

int sumToN(int n);
int palindromeTest(unsigned long int);
char *stringReverse(char *str);
int is_prime(unsigned long int num);
void mpz_triangular(mpz_t rot, mpz_t op);
void mpz_triangular_ui(mpz_t rot, unsigned long int op);

long int factorial(int n);

#endif
