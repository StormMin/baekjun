#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int N, M;
int a[10];
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
		for (int i = x; i <= N; i++) {
			if (b[i] == 0) {
				b[i] = 1;
				a[cnt] = i;
				fun(i,cnt + 1);
				b[i] = 0;
			}
		}
	}
}
int main(void) {
	scanf("%d %d", &N, &M);
	fun(1,0);
	return 0;
}