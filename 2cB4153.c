#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int triangle(int a, int b, int c) {
	if (a == b + c) {
		printf("right\n");
	}
	else printf("wrong\n");
}
int main() {
	int N=1, M=1, k=1;
	while (1) {
		scanf("%d %d %d", &N, &M, &k);
		if (N == 0 && M == 0 && k == 0) break;
		N = N * N;
		M = M * M;
		k = k * k;
		if (N < M) {
			if (M < k) {
				triangle(k, M, N);
			}
			else triangle(M, k, N);
		}
		else if (N < k) {
			if (k < M) {
				triangle(M, k, N);
			}
			else triangle(k, M, N);
		}
		else {
			triangle(N, M, k);
		}
	}
	return 0;
}