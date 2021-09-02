#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int W[100001];
int V[100001];
int dp[101][100001];
int MAX(int a, int b) {
	if (a < b) return b;
	return a;
}
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &W[i], &V[i]);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (W[i] <= j) {
				dp[i][j] = MAX(dp[i - 1][j], V[i] + dp[i - 1][j - W[i]]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	printf("%d", dp[N][K]);
	return 0;
}