#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, M, tmp = 0 , i = 1, j = 1, a, b,elv[999999];
	elv[0] = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		tmp = 0;
		scanf("%d %d", &a, &b);
		for (j = 0; j <= a; j++) {
			if (j == 0) {
				for (int k = 1; k <= b; k++) {
					elv[k] = tmp;
				}
			}
			else {
				for (int k = 1; k <= b; k++) {
					elv[k] = elv[k - 1] + elv[k];
				}
			}
		}
		printf("%d", elv[b]);
	}
	return 0;
}