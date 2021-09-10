#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int N[17][17],size,cnt;
int mov[3][2] = { {0,1},{1,0},{1,1} };
int pipe(int r,int c,int p) {
	if (r == size && c == size) {
		cnt++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if ((i == 0 && p == 1) || (i == 1 && p == 0)) {
			continue;
		}
		int nextr = r + mov[i][0];
		int nextc = c + mov[i][1];
		if (nextr > size || nextc > size||N[nextr][nextc]==1) {
			continue;
		}
		if (i == 2 && (N[nextr - 1][nextc]==1 || N[nextr][nextc - 1]==1)) {
			continue;
		}
		pipe(nextr,nextc,i);
	}
}
int main()
{
	scanf("%d", &size);
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			scanf("%d", &N[i][j]);
		}
	}
	pipe(1, 2,0);
	printf("%d", cnt);
	return 0;
}