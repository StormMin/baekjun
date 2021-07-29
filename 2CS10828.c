#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int a[10001];
	int N,n,k=-1;
	char b[10];
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%s", b);
		if (strcmp(b, "push") == 0) {
			scanf("%d", &n);
			getchar();
			a[++k] = n;
		}
		else if (strcmp(b, "pop") == 0) {
			if (k == -1) printf("-1");
			else
			printf("%d\n", a[k--]);
		}
		else if (strcmp(b, "size") == 0) {
			printf("%d\n", k+1);
		}
		else if (strcmp(b, "empty") == 0) {
			if (k == -1) printf("1");
			else printf("0");
		}
		else if (strcmp(b, "top") == 0) {
			if (k == -1) printf("-1\n");
			else
			printf("%d\n", a[k]);
		}
	}
	return 0;
}