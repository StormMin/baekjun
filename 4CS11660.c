#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int d[1025][1025];
int a[1025][1025];
int main()
{
	int x1, y1, x2, y2;
	int N,M;
	scanf("%d %d", &N,&M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	d[0][0] = a[0][0];
	d[1][0] = d[0][0] + a[1][0];
	d[0][1] = d[0][0] + a[0][1];
	for (int i = 2; i < N; i++) {
		d[0][i] = d[0][i - 1] + a[0][i];
		d[i][0] = d[i - 1][0] + a[i][0];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] +a[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1--;
		y1--;
		x2--;
		y2--;
		int conv1 = d[x1-1][y1-1];
		int conv2 = d[x2][y1 - 1] - conv1;
		int conv3 = d[x1-1][y2] - conv1;
		printf("%d\n", d[x2][y2]-conv1-conv2-conv3);
	}
	return 0;
}
