#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int a[100001];
int main(void) {
	int N, M,x,y,sum=0,tmp;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &tmp);
		a[i] = a[i - 1] + tmp;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		printf("%d\n", a[y]-a[x-1]);
	}
	return 0;
}