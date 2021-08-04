#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int Graph[1001][1001];
int DFSvisit[1001];
int BFSvisit[1001];
int queue[1001];
void dfs(int v, int N) {
	int i;
	DFSvisit[v] = 1;
	printf("%d ", v);
	for (i = 1; i <= N; i++) {
		if (Graph[v][i] == 1 && DFSvisit[i] == 0) {
			dfs(i, N);
		}
	}
}
void bfs(int v,int N) {
	int front = 0, rear = 0, Pop, i;
	printf("%d ", v);
	queue[0] = v;
	rear++;
	BFSvisit[v] = 1;
	while (front < rear) {
		Pop = queue[front++];
		for (i = 1; i <= N; i++) {
			if (Graph[Pop][i] == 1 && BFSvisit[i] == 0) {
				printf("%d ", i);
				queue[rear] = i;
				rear++;
				BFSvisit[i] = 1;
			}
		}
	}
}
int main(void) {
	int N, M, Start;
	int i, x, y;
	scanf("%d%d%d", &N, &M, &Start);
	for (i = 0; i < M; i++) {
		scanf("%d%d", &x, &y);
		Graph[x][y] = 1;
		Graph[y][x] = 1;
	}
	dfs(Start, N);
	printf("\n");
	bfs(Start, N);
	return 0;
}