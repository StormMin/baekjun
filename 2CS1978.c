#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	int N,M,k,cnt=0;
	scanf("%d", &N); 
	for (int i = 0; i < N; i++) {
		scanf("%d", &M);
		k = 0;
		if (M == 1) continue;
		for (int j = 2; j < (M); j++) {
			if (M % j == 0) {
				k++;
			}
		}
		if (k == 0) cnt++;
	}
	printf("%d", cnt);
	return 0;
}