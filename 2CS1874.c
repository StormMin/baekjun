#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int st[100001];
int main(void) {
	int n,N,a[100001],i,j,k=0;
	char pp[200001];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	i = 0;
	j = 1;
	k = 0;
	int q = 0;
	int t = 0;
	while (i < N) {
		if (a[i] > st[k]) {
			if (st[k] != 0) k++;
			pp[t++] = '+';
			st[k] = j++;
		}
		else if (a[i] == st[k]) {
			pp[t++] = '-';
			st[k--] = 0;
			i++;
		}
		else if (a[i] < st[k]) {
			printf("NO\n");
			q = 1;
			break;
		}
}
	if (q != 1) {
		for (i = 0; i < t; i++) {
			printf("%c\n", pp[i]);
		}
	}
	return 0;
}