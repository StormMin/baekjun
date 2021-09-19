#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int a[100001][3],N,ma,mi;
int dp[100001][3];
int MAX(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}
int MIN(int a, int b) {
	if (a > b) return b;
	return a;
}
int index;
int dynamicM() {
	for (int i = 0; i < 3; i++) {
		dp[0][i] = a[0][i];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				dp[i][j] = a[i][j]+ MAX(dp[i - 1][0], dp[i - 1][1]);
			}
			if (j == 1) {
				dp[i][j] = a[i][j]+MAX(dp[i - 1][0], dp[i - 1][1]);
				dp[i][j] = MAX(dp[i][j],a[i][j]+dp[i - 1][2]);
			}
			if (j == 2) {
				dp[i][j] = a[i][j]+MAX(dp[i - 1][1], dp[i - 1][2]);
			}
		}
	}
}
int dynamicN() {
	for (int i = 0; i < 3; i++) {
		dp[0][i] = a[0][i];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				dp[i][j] = a[i][j] + MIN(dp[i - 1][0], dp[i - 1][1]);
			}
			if (j == 1) {
				dp[i][j] = a[i][j] + MIN(dp[i - 1][0], dp[i - 1][1]);
				dp[i][j] = MIN(dp[i][j], a[i][j] + dp[i - 1][2]);
			}
			if (j == 2) {
				dp[i][j] = a[i][j] + MIN(dp[i - 1][1], dp[i - 1][2]);
			}
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	dynamicM();
	ma = MAX(dp[N - 1][0], dp[N - 1][1]);
	ma = MAX(ma, dp[N - 1][2]);
	printf("%d", ma);
	for (int i = 0; i < 2; i++) {
		memset(dp[i], 0, sizeof(dp[i]));
	}
	dynamicN();
	mi = MIN(dp[N - 1][0], dp[N - 1][1]);
	mi = MIN(mi, dp[N - 1][2]);
	printf(" %d", mi);
	return 0;
}