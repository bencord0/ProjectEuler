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
/*
The Fibonacci sequence is defined by the recurrence relation:
Fn = Fn1 + Fn2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:
F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "Problem025.h"

int Problem025(void) {
	const unsigned long int start=0;
	mpz_t n, F,Fsub1,temp; /* n'th term has value F */

	mpz_init(n);mpz_init(F);mpz_init(Fsub1);mpz_init(temp);

	mpz_set_ui(n,start);
	mpz_fib2_ui(F,Fsub1,start);

	do{
		mpz_set(temp,F);
		mpz_add_ui(n,n,1); /*increment*/
		mpz_add(F,F,Fsub1);mpz_set(Fsub1,temp); /*update*/
	}while(mpz_sizeinbase(F,10)<1000);

	/* once more because we want the first one with the required digit count*/
	mpz_set(temp,F);
	mpz_add_ui(n,n,1);
	mpz_add(F,F,Fsub1);
	mpz_set(Fsub1,temp);


	gmp_printf("%30Zd",n);

	mpz_clear(n);mpz_clear(F);mpz_clear(Fsub1);mpz_clear(temp);
	return 0;
}
