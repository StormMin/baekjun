#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>


int main(void) {
	int N;
	long long a[11],M;
	scanf("%d %lld", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
	}
	long long cnt = 0, tmp;
	int i = N - 1, j;
	while (M!=0) {
		if (M >= a[i]) { 
			tmp=M /a[i];
			M %= a[i];
			cnt+=tmp;
		}
		i--;
	}
	printf("%lld", cnt);
	return 0;
}