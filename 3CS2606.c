#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[101];
int getParent(int a[], int x) {
	if (a[x] == x) return x;
	return a[x] = getParent(a, a[x]);
}
int unionParent(int a[], int x, int y) {
	x = getParent(a, x);
	y = getParent(a, y);
	if (x < y) a[y] = x;
	else a[x] = y;
}
int findParent(int a[], int x, int y) {
	x = getParent(a, x);
	y = getParent(a, y);
	if (x == y) return 1;
	return 0;
}
int main(void) {
	int N, M,x,y;
	scanf("%d %d" ,&N, &M);
	for (int i = 1; i <= N; i++) {
		a[i] = i;
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &x, &y);
		unionParent(a, x, y);
	}
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (findParent(a, 1, i) == 1) {
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}