#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

long long a[101];
int main(void) {
	int N,M;
	a[1] = 1;
	a[2] = 1;
	a[3] = 1;
	a[4] = 2;
	a[5] = 2;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &M);
		if (M < 5) {
			printf("%d\n", a[M]);
		}
		else {
			for (int j = 6; j <= M; j++) {
				a[j] = a[j - 5] + a[j - 1];
			}
			printf("%lld\n", a[M]);
		}
	}
	return 0;
}