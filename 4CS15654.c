#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int N, M;
int a[10];
int num[10];
bool b[10];
int fun(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < cnt; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (!b[i]) {
				a[cnt] = num[i];
				b[i] = 1;
				fun(cnt + 1);
				b[i] = 0;
			}
		}
	}
}
int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (num[i] > num[j]) {
				int tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}
	fun(0);
	return 0;
}