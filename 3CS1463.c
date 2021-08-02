#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dp[100000];
int main(void) {
	int N, M,cnt=0;
	scanf("%d", &M);
	for (int i = 2; i <= M; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2]+1) {
				dp[i] = dp[i / 2] + 1;
			}
		}
		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3] + 1) {
				dp[i] = dp[i / 3] + 1;
			}
		}
	}
	printf("%d", dp[M]);
	return 0;
}