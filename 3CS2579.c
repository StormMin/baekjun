#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dp[100000];
int ma(int a, int b) {
	if (a > b) return a;
	return b;
}
int main(void) {
	int N, M, cnt = 0;
	int stair[300];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &stair[i]);
	}
	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	dp[2] = ma(stair[0] + stair[2], stair[1] + stair[2]);
	for (int i = 3; i < N; i++) {
		dp[i] = dp[i - 3] + stair[i - 1]+stair[i];
		dp[i] = ma(dp[i], dp[i - 2] + stair[i]);
	}
	printf("%d", dp[N - 1]);
	return 0;
}