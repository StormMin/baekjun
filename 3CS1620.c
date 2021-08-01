#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Pok {
	char name[21];
	int order;
}Pok;
int main(void) {
	int N,M,c=1,root=0;
	Pok a[1000],T,same[1000];
	char b[21];
	scanf("%d %d", &N,&M);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%s", a[i].name);
		a[i].order = i+1;
		same[i] = a[i];
	}
	for (int i = 0; i < N; i++) {
		c = i;
		do {
			root = (c - 1) / 2;
			if (strcmp(a[c].name, a[root].name) > 0) {
				T = a[c];
				a[c] = a[root];
				a[root] = T;
			}
			c = root;
		} while (c!=0);
	}
	for (int i = N - 1; i >= 0; i--) {
		T = a[0];
		a[0] = a[i];
		a[i] = T;
		c = 1;
		root = 0;
		do {
			c = root * 2 + 1;
			if (c < i - 1 && (strcmp(a[c].name, a[c + 1].name) < 0)) {
				c++;
			}
			if (c < i && (strcmp(a[c].name, a[root].name) > 0)) {
				T = a[c];
				a[c] = a[root];
				a[root] = T;
			}
			root = c;
		} while (c<i);
	}
	for (int j = 1; j <= M; j++) {
		scanf("%s", b);
		if (b[0] >= '0' && b[0] <= '9') {
			c = atoi(b);
			printf("%s\n", same[c-1].name);
		}
		else {
			int low = 0, mid, high = N;
			while (low <= high) {
				mid = (low + high) / 2;
				if (strcmp(a[mid].name, b) > 0) {
					high = mid - 1;
				}
				else if (strcmp(a[mid].name, b) == 0) {
					printf("%d\n", a[mid].order);
					break;
				}
				else {
					low = mid + 1;
				}
			}
		}
	}
	return 0;
}