#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}
int unionParent(int parent[], int a, int b) {
	a = getParent(parent,a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	return 0;
}
int party[51][51];
bool pred[51];
int main()
{
	int parent[51];
	int TN[50];
	int N, M,T,P;
	scanf("%d %d", &N, &M);
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &TN[i]);
	}
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d", &P);
		int num, prev;
		for (int j = 1; j <= P; j++) {
			if (j > 1) {
				prev = num;
				scanf("%d", &num);
				unionParent(parent, num, prev);
			}
			else scanf("%d", &num);
			party[i][j]=num;
		}
	}
	for (int i = 0; i < T; i++) {
		int tmp = TN[i];
		for (int i = 1; i <= N; i++) {
			if (!pred[i]) {
				if (findParent(parent, tmp, i)) {
					pred[i] = true;
				}
			}
		}
	}
	int cnt=0;
	for (int i = 1; i <= M; i++) {
		int j = 1;
		int k = 0;
		while (party[i][j] != 0) {
			if (pred[party[i][j]]) {
				k = 1;
				break;
			}
			j++;
		}
		if (k == 0) {
			cnt++;
		}
	}
	printf("%d", cnt);


	return 0;
}