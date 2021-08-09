#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[101][101];
int INF = 100000000;
void floydWarshall(int number) {
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (i == j) {
				a[i][j] == 0;
			}
			else if (a[i][j] == 1) {
				continue;
			}
			else {
				a[i][j] = INF;
			}
		}
	}
	for (int k = 0; k < number; k++) {
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				if (a[i][k] + a[k][j] < a[i][j]) {
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}
	int min_ba = 100000, cnt = 0,person=0;
	for (int i = 0; i < number; i++) {
		cnt = 0;
		for (int j = 0; j < number; j++) {
			cnt += a[i][j];
		}
		if (min_ba > cnt) {
			min_ba = cnt;
			person = i;
		}
	}
	printf("%d", person+1);
}
int main(void) {
	int N, M,x,y;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		a[x-1][y-1] = 1;
		a[y-1][x-1] = 1;
	}
	floydWarshall(N);
	return 0;
}