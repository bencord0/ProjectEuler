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
#include <stdio.h>
#include "Problem018.h"

int Problem018() {
	int tree[] = {
	75,
	95,64,
	17,47,82,
	18,35,87,10,
	20, 4,82,47,65,
	19, 1,23,75, 3,34,
	88, 2,77,73, 7,63,67,
	99,65, 4,28, 6,16,70,92,
	41,41,26,56,83,40,80,70,33,
	41,48,72,33,47,32,37,16,94,29,
	53,71,44,65,25,43,91,52,97,51,14,
	70,11,33,28,77,73,17,78,39,68,17,57,
	91,71,52,38,17,14,91,43,58,50,27,29,48,
	63,66, 4,68,89,53,67,30,73,16,69,87,40,31,
	 4,62,98,27,23, 9,70,98,73,93,38,53,60, 4,23};
	int max[120]; /* 120 = 15 + 14 + 13...+1 */
	int row;
	int row_start;
	int row_end;
	int a, b;
	int i;

	row = 0;
	row_start = 0;
	row_end = 0;
	i = 0;

return 1; /* XXX no illusions, this isn't right yet. */

	max[0] = tree[0];
	++row;
	while (row < 15 ) {
		row_start = row_end + 1;
		row_end = row_start + row;
		max[row_start] = tree[row_start] + max[row_start - row];
		max[row_end] = tree[row_end] + max[row_start - 1];
		for(i = 1; i< row; ++i) {
			a = tree[i] + max[i - row];
			b = tree[i] + max[i + 1 - row];
			max[i] = (a>b)?a:b;
		}

		++row;
	}

	for(i=104;i<120;++i) {
		b = max[i];
		a = (a>b)?a:b;
	}

	printf("%30d", a);
	return 0;
}
