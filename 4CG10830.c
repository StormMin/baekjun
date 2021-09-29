#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int N[6][6], n;
long long b;
int d[6][6];
int idx,idy;
int matrix(int s[][6],int t[][6]) {
	int resulted[6][6] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			idx = 0;
			while (idx<n) {
				resulted[i][j] += (s[idx][j] * t[i][idx])%1000;
				idx++;
			}
			resulted[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			s[i][j] = resulted[i][j];
		}
	}
}
int main() {
	scanf("%d %lld", &n,&b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &N[i][j]);
		}
	}
	int k = 0;
	while (b != 1) {
		if (b % 2 == 1) {
			if (k == 0) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						d[i][j] = N[i][j];
					}
				}
				k = 1;
			}
			b--;
		}
		else {
			b = b / 2;
			matrix(N, N);
		}
	}
	if (k==1)
	matrix(N, d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", (N[i][j])%1000);
		}
		printf("\n");
	}
	return 0;
}