#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
bool visited[10001];
int g[10001][10001],N,ans,end_point;
int DFS(int x,int length) {
	if (visited[x]) {
		return;
	}
	visited[x] = true;
	if (ans < length) {
		ans = length;
		end_point = x;
	}
	for (int i = 2; i <= N; i++) {
		if (g[x][i]!=0) {
			DFS(i, length+g[x][i]);
		}
	}
}
int main(){
	scanf("%d", &N);
	int r, c, e;
	for (int i = 0; i < N-1; i++) {
		scanf("%d %d %d", &r, &c, &e);
		g[r][c] = e;
		g[c][r] = e;
	}
	DFS(1, 0);
	ans = 0;
	memset(visited, false, sizeof(visited));
	DFS(end_point, 0);
	printf("%d", ans);
	return 0;
}