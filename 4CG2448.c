#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
char map[4000][8000];
int star(int n,int x,int y) {
	if (n == 3) {
		map[x][y] = '*';
		map[x + 1][y - 1] = '*';
		map[x + 1][y + 1] = '*';
		map[x + 2][y - 2] = '*';
		map[x + 2][y - 1] = '*';
		map[x + 2][y] = '*';
		map[x + 2][y +1] = '*';
		map[x + 2][y + 2] = '*';
		return;
	}
	star(n / 2, x, y);
	star(n / 2, x + n / 2, y - n / 2);
	star(n / 2, x + n / 2, y + n / 2);
}
int main() {
	int N;
	scanf("%d", &N);
	star(N, 0, N-1);
	for (int i = 0; i < N; i++) {
		for (int j = 0;j < N *2-1; j++) {
			if (map[i][j] == '*')
				printf("%c", map[i][j]);
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}