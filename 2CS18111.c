#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	int N, M, B,a[500][500],prob=0,time=0,Mt=555555;
	scanf("%d %d %d", &N, &M, &B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int x = 0;x <= 256; x++) {
		int time = 0,inv=B;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (x > a[i][j]) {
					time += x - a[i][j];
					inv -= x - a[i][j];
				}
				else if (x < a[i][j]) {
					time += (a[i][j] - x) * 2;
					inv += a[i][j] - x;
				}
			}
		}
		if (Mt >= time&&inv>=0) {
			Mt = time;
			prob = x;
		}
	}
	printf("%d %d", Mt, prob);
	return 0;
}