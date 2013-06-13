/*
* Copyright 2013 Ben Cordero
*
* This file is part of my ProjectEuler implementations.
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
