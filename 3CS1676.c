#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	int N,cnt=0;
	scanf("%d", &N);
	for (int i = 5; i <= N; i *= 5) {
		cnt += (N / 5);
	}
	printf("%d\n", cnt);
	return 0;
}