#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	int a[20001];
	int N,n,k=10000,l=10001;
	char b[15];
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%s", b);
		if (strcmp(b, "push_front") == 0) {
			scanf("%d", &n);
			getchar();
			a[++k] = n;
		}
		if (strcmp(b, "push_back") == 0) {
			scanf("%d", &n);
			getchar();
			a[--l]=n;
		}
		else if (strcmp(b, "pop_front") == 0) {
			if (l>k) printf("-1\n");
			else
			printf("%d\n", a[k--]);
		}
		else if (strcmp(b, "pop_back") == 0) {
			if (k < l) printf("-1\n");
			else
				printf("%d\n", a[l++]);
		}
		else if (strcmp(b, "size") == 0) {
			printf("%d\n", k-l);
		}
		else if (strcmp(b, "empty") == 0) {
			if (k < l) printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(b, "front") == 0) {
			if (k < l) printf("-1\n");
			else
			printf("%d\n", a[k]);
		}
		else if (strcmp(b, "back") == 0) {
			if (k < l) printf("-1\n");
			else
			printf("%d\n", a[l]);
		}
	}
	return 0;
}