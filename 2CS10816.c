#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int MAX=10000000;
int cnt[20000001];
int main(void) {
	int N, M, n;
	int b;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n); 
		if (n < 0) {
			cnt[MAX + (n*(-1))]++;
		}
		else {
			cnt[n]++;
		}
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &b);
		if (b < 0) {
				printf("%d ", cnt[MAX + (b * (-1))]);
		}
		else {
			printf("%d ",cnt[b]);
		}
	}
	return 0;
}