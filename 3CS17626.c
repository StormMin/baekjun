#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
int dp[50001];
int f(int x) {
	int min = 0;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= x; i++) {
		min = 5;
		for (int j = 1; j <= sqrt(i); j++) {
				if (min> dp[i - j * j] + 1)
				min = dp[i - j * j] + 1;
		}
		dp[i] = min;
	}
	return dp[x];
}
int main(void) {
	int N;
	scanf("%d", &N);
	printf("%d", f(N));
	return 0;
}