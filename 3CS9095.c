#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int a[12];
int sum123(int a[], int k) {
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
	if (k < 4) printf("%d", a[k]);
	else {
		for (int i = 4; i <= k; i++) {
			a[i] = a[i - 1] + a[i - 2] + a[i - 3];
		}
	printf("%d\n", a[k]);
	}
}
int main(void) {
	int N,M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &M);
		sum123(a, M);
	}
	return 0;
}