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
int fun(int x,int cnt) {
	if (cnt == M) {
		for (int i = 0; i < cnt; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		return;
	}
	else {
		for (int i = x; i < N; i++) {
				a[cnt] = num[i];
				fun(i,cnt + 1);
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
	fun(0,0);
	return 0;
}