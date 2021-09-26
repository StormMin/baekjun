#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int N, M;
int map[101][101];
typedef struct {
	int y, x;
}mo;
mo movedir[4] = { {1,0},{0,1},{-1,0},{0,-1} };
mo tmp[1000001];
int front = -1, rear = -1,cmp,cnt;
int dup[101][101];
int dfs(int y,int x) {
	if (dup[y][x] == 0) {
		dup[y][x] = 2;
	}
	for (int i = 0; i < 4; i++) {
		int nextX = movedir[i].x + x;
		int nextY = movedir[i].y +y;
		if (nextX >= 0 && nextY >= 0 && nextX < M && nextY < N&&dup[nextY][nextX]==0) {
			dfs(nextY, nextX);
		}
	}
}
int ch(int y,int x) {
	int t = 0;
	for (int i = 0; i < 4; i++) {
		int nextX = movedir[i].x + x;
		int nextY = movedir[i].y + y;
		if (nextX >= 0 && nextY >= 0 && nextX < M && nextY < N && dup[nextY][nextX] == 2) {
			t++;
		}
	}
	if (t >= 2) {
		tmp[cmp].y = y;
		tmp[cmp++].x = x;
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (1) {
		cmp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				dup[i][j] = map[i][j];
			}
		}
		dfs(0, 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (dup[i][j] == 1) {
					ch(i, j);
				}
			}
		}
		for (int i = 0; i < cmp; i++) {
			map[tmp[i].y][tmp[i].x] = 0;
		}
		if (cmp == 0) break;
		cnt++;
	}
	printf("%d", cnt);

	return 0;
}