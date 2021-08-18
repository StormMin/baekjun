#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int d[2][100001];
int MAX(int a, int b) {
	if (a < b) return b;
	return a;
}
int main(void) {
	int a[2][100000], N;
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		d[0][0] = 0;
		d[1][0] = 0;
		d[0][1] = a[0][0];
		d[1][1] = a[1][0];
		for (int i = 2; i <= N; i++) {
			d[0][i] = MAX(d[1][i - 2], d[1][i - 1]) + a[0][i-1];

			d[1][i] = MAX(d[0][i - 2], d[0][i - 1]) + a[1][i-1];
		}
		printf("%d\n", MAX(d[0][N], d[1][N]));
	}

	return 0;
}