#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct password {
	char site[21];
	char pw[21];
}PW;
int heap(PW LC[], int N) {
	PW tmp;
	int c = 1, root = 0;
	for (int i = 1; i < N; i++) {
		c = i;
		do {
			root = (c - 1) / 2;
			if (strcmp(LC[c].site, LC[root].site) > 0) {
				tmp = LC[c];
				LC[c] = LC[root];
				LC[root] = tmp;
			}
			c = root;
		} while (c != 0);
	}
	for (int i = N - 1; i >= 0; i--) {
		tmp = LC[0];
		LC[0] = LC[i];
		LC[i] = tmp;
		root = 0;
		c = 1;
		do {
			c = root * 2 + 1;
			if (c < i - 1 && (strcmp(LC[c].site, LC[c + 1].site) < 0)) {
				c++;
			}
			if (c < i && (strcmp(LC[c].site, LC[root].site) > 0)) {
				tmp = LC[c];
				LC[c] = LC[root];
				LC[root] = tmp;
			}
			root = c;
		} while (c < i);
	}
}
int main(void) {
	int N, M;
	char b[21];
	PW a[100001];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s %s", a[i].site,a[i].pw);
	}
	heap(a, N);
	for (int j = 0; j < M; j++) {
		scanf("%s", b);
		for (int i = 0; i < N; i++) {
			int low = 0, mid, high = N-1;
			while (low <= high) {
				mid = (low + high) / 2;
				if (strcmp(a[i].site, b) > 0) {
					low = mid + 1;
				}
				else if (strcmp(a[i].site, b) == 0) {
					printf("%s\n",a[i].pw);
					break;
				}
				else {
					high = mid - 1;
				}
			}
		}
	}
	return 0;
}