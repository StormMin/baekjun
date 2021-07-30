#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ap[1000000];
int main(void) {
	int N,M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i <= M; i++) {
		ap[i] = i;
	}
	ap[1] = 0;
	for (int i = 2; i <= M; i++) {
		if (ap[i] == 0) continue;
		for (int j = i + i; j <= M; j+=i) {
			ap[j] = 0;
		}
	}
	for (int i = N; i <= M; i++) {
		if (ap[i] != 0) {
			printf("%d\n", ap[i]);
		}
	}
	return 0;
}