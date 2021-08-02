#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dp[41],z[41],o[41];
int fib(int x) {
	if (x <= 0) {
		dp[0] = 0;
		return 0;
	}
	if (x == 1) {
		dp[1] = 1;
		return 1;
	}
	if (dp[x] != 0) {
		return dp[x]; 
	}

	return dp[x] = fib(x - 1) + fib(x - 2);
}
int main(void) {
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &M);
		if (M == 0) {
			printf("1 0\n");
		}
		else if (M == 1) {
			printf("0 1\n");
		}
		else {
			printf("%d %d\n", fib(M - 1), fib(M));
		}
	}
	return 0;
}