/**
 * The sum of the squares of the first ten natural numbers is,
 * 1² + 2² + ... + 10² = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)² = 55² = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural numbers and
 * the square of the sum is 3025 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred natural numbers
 * and the square of the sum.
 */
#include <stdio.h>

int Problem006(void) {
	int input = 100;
	int i;
	int squareSum;
	int sumSquares;

	for( i=1, sumSquares=0, squareSum=0; i<=input; i++)	{
		sumSquares += i*i;
		squareSum += i;
	}

	squareSum = squareSum*squareSum;

	printf("%d", (squareSum - sumSquares) );
	return 0;
}
