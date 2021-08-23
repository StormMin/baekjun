#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int a[1000][3];
int d[1000][3];
int MIN(int x, int y) {
	if (x < y) return x;
	return y;
}
int main()
{
	int N,i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	}
	d[0][0] = a[0][0];
	d[0][1] = a[0][1];
	d[0][2] = a[0][2];
	for (i = 1; i < N; i++) {
		d[i][0] = MIN(d[i - 1][1], d[i - 1][2]) + a[i][0];
		d[i][1] = MIN(d[i - 1][0], d[i - 1][2]) + a[i][1];
		d[i][2] = MIN(d[i - 1][0], d[i - 1][1]) + a[i][2];
	}
	int m = MIN(d[N - 1][0],d[N - 1][1]);
	m = MIN(m,d[N - 1][2]);
	printf("%d", m);
	return 0;
}
