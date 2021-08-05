#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
int result[3];
int map[2200][2200];
bool check(int x, int y,int N) {
	int start = map[x][y];
	for (int i = x; i < N+x; i++) {
		for (int j = y; j < N+y; j++) {
			if (start != map[i][j]) {
				return false;
			}
		}
	}
	return true;
}
int divide(int x,int y,int N) {
	if (check(x, y, N)==1) {
		result[map[x][y]]++;
	}
	else {
		int size = N / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divide(x+size * i, y+size * j, size);
			}
		}
	}
}
int main(void) {
	int N,tmp;
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &tmp);
			tmp++;
			map[i][j] = tmp;
		}
	}
	divide(0, 0, N);
	printf("%d\n%d\n%d", result[0], result[1], result[2]);
	return 0;
}