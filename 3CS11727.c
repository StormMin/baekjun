#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int a[1001];
int main(void) {
	int N, M, i = 1;
	scanf("%d", &N);
	a[1] = 1;
	a[2] = 3;
	if (N < 3) {
		printf("%d", a[N]);
	}
	else {
		for (int j = 3; j <= N; j++) {
			a[j] = (a[j - 1] + a[j-2]*2)%10007;
		}

	printf("%d", a[N]);
	}
	return 0;
}