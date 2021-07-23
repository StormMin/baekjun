#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, M, tmp = 0, i = 1, j = 1,k, a[100],max=0;
	scanf("%d %d", &N,&M);
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			for (k = j + 1; k < N; k++) {
				if ((a[i] + a[j] + a[k] <= M) && (a[i] + a[j] + a[k] > max))
					max = a[i] + a[j] + a[k];
			}
		}
	}
	printf("%d", max);
	return 0;
}