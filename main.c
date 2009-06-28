#include <stdio.h>
#include <time.h>
#include "euler.h"

int no_problem(void) {return 1;}
int wrap(int (*prog)(void));

int main(int argc, char **argv) {
	int p_count = 0;
	int check, i;
	int working = 0;
	int (*prog[MAX_PROGRAM_COUNT +1])(void);

	/**
	 * Unfortunatly, in C there is no way around this map.
	 * Don't forget to redefine MAX_PROGRAM_COUNT in euler.h
	 */

	while(p_count<=MAX_PROGRAM_COUNT)
		prog[p_count++]=no_problem;

	prog[1] = Problem001;
	prog[2] = Problem002;
	prog[3] = Problem003;
	prog[4] = Problem004;
	prog[5] = Problem005;
	prog[6] = Problem006;
	prog[7] = Problem007;
	prog[8] = Problem008;
	prog[9] = Problem009;
	prog[10] = Problem010;
	prog[11] = Problem011;
	prog[12] = Problem012;
	prog[13] = Problem013;
	prog[14] = Problem014;
	prog[15] = Problem015;
	prog[16] = Problem016;
	prog[17] = Problem017;
	prog[18] = Problem018;
	prog[20] = Problem020;
	prog[21] = Problem021;
	prog[23] = Problem023;
	prog[25] = Problem025;
	prog[34] = no_problem;
	prog[45] = Problem045;
	prog[48] = Problem048;
	prog[53] = Problem053;
	prog[57] = Problem057;
	prog[59] = Problem059;

	printf("Prime generator mode: %d\n", generate_primes(10000000));

	if(argc>1) {
		/**
		 * for each number specified on command line, run that problem
		 * ignore others
		 */
		i = 1;
		while(argc>i) {
			if(sscanf(argv[i++], "%d", &p_count)) {
				if(p_count > MAX_PROGRAM_COUNT || wrap(prog[p_count])) {
					printf("NOT IMPLEMENTED !!!");
				}
			}
			printf("\n");
		}
	} else {
		/**
		* Select each sub program in turn or die.
		*/
		for(p_count=1;p_count <= MAX_PROGRAM_COUNT;p_count++) {
			printf("Problem%3d: ", p_count);

			check = wrap(prog[p_count]);
			switch (check) {
				case 0:
				/* Success */
				working++;
				printf("\n");
				break;

				case 1:
				default:
				/* Fail */
				printf("\b\b\b\b\b\b\b\b\b\b\b\b");
				break;

				case 2:
				/* Memory/File error */
				printf("Memory or File allocation error\n");
				break;
			}
		}
		printf("%d Problems solved", working);
	}

	printf("\nTotal program time is %.3fs\n", (double) clock()/CLOCKS_PER_SEC );

	return 0;
}

int wrap(int (*prog)(void)) {
	int ret;
	double CLOCK_START;
	double CLOCK_END;

	CLOCK_START = clock();
	ret = (prog());
	CLOCK_END = clock();

	if(!ret)
		printf("\t%.3fs", (CLOCK_END - CLOCK_START)/CLOCKS_PER_SEC);
	return ret;
}
