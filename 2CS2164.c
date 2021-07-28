#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	int N,i,j;
	scanf("%d", &N);
	int a[1000001];
	i = 0;
	j = N-1;
	for (int t = 0; t < N; t++) {
		a[t] = t + 1;
	}
	while (i != j) {
		a[i] = 0;
		i++;
		j++;
		a[j] = a[i];
		i++;
	}
	printf("%d", a[i]);
	return 0;
}