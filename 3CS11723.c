#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tmp=0;
int ap[25];
int add(int ap[], int x) {
	for (int i = 0; i < 20; i++) {
		if (ap[i] == x) {
			return;
		}
	}
	for (int i = 0; i < 20; i++) {
		if (ap[i] == 0) {
			ap[i] = x;
			return;
		}
	}
}
int remover(int ap[], int x) {
	for (int i = 0; i < 20; i++) {
		if (ap[i] == x) {
			ap[i] = 0;
		}
	}
}
int check(int ap[], int x) {
	for (int i = 0; i < 20; i++) {
		if (ap[i] == x) {
			printf("1\n");
			return;
		}
	}
	printf("0\n");
}
int toggle(int ap[], int x) {
	for (int i = 0; i < 20; i++) {
		if (ap[i] == x) {
			ap[i] = 0;
			return;
		}
	}
	for (int i = 0; i < 20; i++) {
		if (ap[i] == 0) {
			ap[i] = x;
			return;
		}
	}
}
int all(int ap[]) {
	for (int i = 0; i < 20; i++) {
		ap[i] = i + 1;
	}
}
int empty(int ap[]) {
	for (int i = 0; i < 20; i++) {
		ap[i] = 0;
	}
}
int main(void) {
	int N,x;
	char a[10];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%s", a);
		if (strcmp(a, "add") == 0) {
			scanf("%d", &x);
			add(ap, x);
		}
		else if (strcmp(a, "remove") == 0) {
			scanf("%d", &x);
			remover(ap, x);
		}
		else if (strcmp(a, "check") == 0) {
			scanf("%d", &x);
			check(ap, x);
		}
		else if (strcmp(a, "toggle") == 0) {
			scanf("%d", &x);
			toggle(ap, x);
		}
		else if (strcmp(a, "all") == 0) {
			all(ap);
		}
		else if (strcmp(a, "empty") == 0) {
			empty(ap);
		}
	}
	return 0;
}