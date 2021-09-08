#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int N;
int dp[1000011];
int st[1000011];
int M(int x, int y) {
	if (x < y) return x;
	return y;
}
int main()
{
	int i = 0;
	scanf("%d", &N);
	st[1] = 1;
	for (i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		st[i] = i - 1;
		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2] + 1) {
				dp[i] = dp[i / 2] + 1;
				st[i] = i / 2;
			}
		}
		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3] + 1) {
				dp[i] = dp[i / 3] + 1;
				st[i] = i / 3;
			}
		}
	}
	int p = N;
	printf("%d\n", dp[p]);
	for (i = 0; i <= dp[p]; i++) {
		if (i == 0) printf("%d ", N);
		else {
			printf("%d ", st[N]);
			N = st[N];
		}
	}
	return 0;
}