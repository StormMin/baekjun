#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int d[501][501];
int a[501][501];
int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	d[1][0] = a[1][0];
	d[2][0] = a[2][0] + a[1][0];
	d[2][1] = a[2][1] + a[1][0];
	for (int i = 3; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (j == 0) d[i][j] = d[i - 1][j] + a[i][j];
			else if (j == i - 1) {
				d[i][j] = d[i - 1][j - 1] + a[i][j];
			}
			else {
				d[i][j] = MAX(d[i - 1][j], d[i - 1][j - 1]) + a[i][j];
			}
		}
	}
	int m = d[N][0];
	for (int i = 1; i < N; i++) {
		if (m < d[N][i]) {
			m = d[N][i];
		}
	}
	printf("%d",m);
	return 0;
}
