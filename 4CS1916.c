#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
long long INF = 987654321;
int N, M;
bool v[10000],vs[1002][1002];
long long d[10000];
int G[1002][1002];
int get() {
	long long min = INF;
	int index = 0;
	for (int i = 1; i <= N; i++) {
		if (d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}
int di(int x) {
	for (int i = 1; i <= N; i++) {
		d[i] = G[x][i];
	}
	v[x] = 1;
	for (int i = 1; i <= N - 2; i++) {
		int current = get();
		v[current] = 1;
		for (int j = 1; j <= N; j++) {
			if (!v[j]) {
				if (d[current] + G[current][j] < d[j]) {
					d[j] = d[current] + G[current][j];
				}
			}
		}
	}
}
int main()
{
	int x, y, z;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &x, &y, &z);
		if (vs[x][y]) {
			if (z < G[x][y]) {
				G[x][y] = z;
			}
		}
		else {
			G[x][y] = z;
		}
		vs[x][y] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j&&!vs[i][j]) {
				G[i][j] = INF;
			}
		}
	}
	scanf("%d %d", &x, &y);
	di(x);
	printf("%lld", d[y]);

	return 0;
}
