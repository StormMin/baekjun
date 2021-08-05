#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int Graph[1001][1001];
int sucess[1001][1001];
int DFSvisit[1001];
int BFSvisit[1001];
int queue[1001];
void dfs(int x,int y,int N,int M) {
	Graph[x][y] = 0;
	if (x + 1 < N && Graph[x + 1][y] == 1) dfs(x + 1, y,N,M);
	if (y + 1 < M && Graph[x][y+1] == 1) dfs(x, y+1, N, M);
	if (x-1 >= 0 && Graph[x -1][y] == 1) dfs(x-1, y, N, M);
	if (x-1 >= 0 && Graph[x][y-1] == 1) dfs(x, y-1, N, M);
	return;
}
int main(void) {
	int N, M,T,K,i,j,x,y,p;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d%d%d", &N, &M, &K);
		for (j = 0; j < K; j++) {
			scanf("%d%d", &x, &y);
			Graph[x][y] = 1;
		}
		int cnt = 0;
		for (j = 0; j < N; j++) {
			for (p = 0; p < M; p++) {
				if (Graph[j][p] == 1) {
					dfs(j, p, N, M);
					cnt++;
				}
			}
		}

		printf("%d", cnt);
	}
	return 0;
}