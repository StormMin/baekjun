#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	int N,M;
	int a[100001];
	int p = -1;
	int sum=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &M);
		if (M == 0) {
			p--;
		}
		else {
			p++;
			a[p] = M;
		}
	}
	for (int i = 0; i <= p; i++) {
		sum += a[i];
	}
	printf("%d", sum);
	return 0;
}