#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int heap(char LC[][21],int N) {
	char a[21];
	int c = 1, root = 0;
	for (int i = 1; i < N; i++) {
		c = i;
		do {
			root = (c - 1) / 2;
			if (strcmp(LC[c], LC[root]) > 0) {
				strcpy(a, LC[c]);
				strcpy(LC[c], LC[root]);
				strcpy(LC[root], a);
			}
			c = root;
		} while (c != 0);
	}
	for (int i = N - 1; i >= 0; i--) {
		strcpy(a, LC[0]);
		strcpy(LC[0], LC[i]);
		strcpy(LC[i], a);
		root = 0;
		c = 1;
		do {
			c = root * 2 + 1;
			if (c < i - 1 && (strcmp(LC[c], LC[c + 1]) < 0)) {
				c++;
			}
			if (c < i && (strcmp(LC[c], LC[root]) > 0)) {
				strcpy(a, LC[c]);
				strcpy(LC[c], LC[root]);
				strcpy(LC[root], a);
			}
			root = c;
		} while (c<i);
	}
}
int main(void) {
	int N, M, cnt = 0,k=0;
	char RC[5000][21], LC[5000][21], a[21],ans[5000][21];
	scanf("%d %d", &N, &M);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%s", LC[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%s", RC[i]);
	}
	heap(LC, N);
	heap(RC, M);
	for (int i = 0; i < N; i++) {
		int low = 0, mid, high = M;
		while (low <= high) {
			mid = (low + high) / 2;
			if (strcmp(LC[i],RC[mid]) > 0) {
				low = mid + 1;
			}
			else if (strcmp(LC[i], RC[mid]) == 0) {
				strcpy(ans[cnt++], LC[i]);
				break;
			}
			else {
				high = mid - 1;
			}
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%s\n", ans[i]);
	}
}