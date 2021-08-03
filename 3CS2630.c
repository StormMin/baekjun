#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
bool b[128][128];
int main(void) {
	int N,a[128][128],M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int i, j, k = 0, row = 0, col = 0, ont = 0, znt = 0, stand = (M * M) / 4, white = 0,blue=0;
	N = M;
	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			if (a[i][j] == 0) {
				znt++;
			}
			else ont++;
		}
	}
	if (znt == M * M) white++;
	if (ont==M*M) blue++;
	if (blue == 0 && white == 0) {
		while (N != 1) {
			for (i = row; i < N / 2 + row; i++) {
				for (j = col; j < N / 2 + col; j++) {
					if (b[i][j] == 0) {
						if (a[i][j] == 0) znt++;
						else ont++;
					}
				}
			}
			if (znt == stand) {
				white++;
				for (i = row; i < N / 2 + row; i++) {
					for (j = col; j < N / 2 + col; j++) {
						b[i][j] = 1;
					}
				}
			}
			if (ont == stand) {
				blue++;
				for (i = row; i < N / 2 + row; i++) {
					for (j = col; j < N / 2 + col; j++) {
						b[i][j] = 1;
					}
				}
			}
			znt = 0;
			ont = 0;
			for (i = row; i < N / 2 + row; i++) {
				for (j = N / 2 + col; j < N + col; j++) {
					if (b[i][j] == 0) {
						if (a[i][j] == 0) {
							znt++;
						}
						else {
							ont++;
						}
					}
				}
			}
			if (znt == stand) {
				white++;
				for (i = row; i < N / 2 + row; i++) {
					for (j = N / 2 + col; j < N + col; j++) {
						b[i][j] = 1;
					}
				}
			}
			if (ont == stand) {
				blue++;
				for (i = row; i < N / 2 + row; i++) {
					for (j = N / 2 + col; j < N + col; j++) {
						b[i][j] = 1;
					}
				}
			}
			znt = 0;
			ont = 0;
			for (i = N / 2 + row; i < N + row; i++) {
				for (j = col; j < N / 2 + col; j++) {
					if (b[i][j] == 0) {
						if (a[i][j] == 0) znt++;
						else ont++;
					}
				}
			}
			if (znt == stand) {
				white++;
				for (i = N / 2 + row; i < N + row; i++) {
					for (j = col; j < N / 2 + col; j++) {
						b[i][j] = 1;
					}
				}
			}
			if (ont == stand) {
				blue++;
				for (i = N / 2 + row; i < N + row; i++) {
					for (j = col; j < N / 2 + col; j++) {
						b[i][j] = 1;
					}
				}
			}
			znt = 0;
			ont = 0;
			for (i = N / 2 + row; i < N + row; i++) {
				for (j = N / 2 + col; j < N + col; j++) {
					if (b[i][j] == 0) {
						if (a[i][j] == 0) znt++;
						else ont++;
					}
				}
			}
			if (znt == stand) {
				white++;
				for (i = N / 2 + row; i < N + row; i++) {
					for (j = N / 2 + col; j < N + col; j++) {
						b[i][j] = 1;
					}
				}
			}
			if (ont == stand) {
				blue++;
				for (i = N / 2 + row; i < N + row; i++) {
					for (j = N / 2 + col; j < N + col; j++) {
						b[i][j] = 1;
					}
				}
			}
			znt = 0;
			ont = 0;
			if (i != M) {
				row += N / 2;
			}
			else if (j != M) {
				col += N / 2;
				row = 0;
			}
			else if (i == M && j == M) {
				N = N / 2;
				row = 0;
				col = 0;
				stand /= 4;
			}
		}
		for (i = 0; i < M; i++) {
			for (j = 0; j < M; j++) {
				if (b[i][j] == 0) {
					if (a[i][j] == 0) white++;
					else blue++;
				}
			}
		}
	}
	printf("%d\n%d", white, blue);
	return 0;
}