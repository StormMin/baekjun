#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int a[10001],c[10],N,M;
bool b[10];
int fun(int x, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < cnt; i++) {
			printf("%d ", c[i]);
		}
		printf("\n");
		return;
	}
	for (int i = x; i <= 10000; i++) {
		if (a[i] > 0) {
			c[cnt] = i;
			fun(i, cnt + 1);
		}
	}
}
int main()
{
	int x;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		a[x]++;
	}
	fun(1, 0);
	return 0;
}
