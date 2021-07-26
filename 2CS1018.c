
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	char a[50][50];
	int N, M,i,j,k,t,cnt = 0, bnt = 0, min = 99999;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
			scanf("%s",&a[i]);
	}
	for (i = 0; i < N - 7; i++) {
		for (j = 0; j < M - 7; j++) {
			cnt = 0;
			bnt = 0;
			for (k = i; k < i+8; k++) {
				for (t = j; t < j + 8; t++) {
					if (((k) + (t)) % 2 == 0) {
						if (a[k][t] == 'B') {
							bnt++;
						}
						else {
							cnt++;
						}
					}
					else {
						if (a[k][t] == 'B') {
							cnt++;
						}
						else {
							bnt++;
						}
					}
				}
			}
			if (min > cnt) {
				min = cnt;
			}
			if (min > bnt) {
				min = bnt;
			}
		}
	}
	printf("%d", min);
	return 0;
}