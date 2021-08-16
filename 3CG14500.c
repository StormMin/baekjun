#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int max;
bool visited[500][500];
int N, M,poly[500][500];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int dfs(int cnt,int y,int x,int sum) {
	visited[y][x] = 1;
	sum+=poly[y][x];
	if (cnt == 4) {
		if (max < sum) max = sum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visited[ny][nx] == 0 && nx >= 0 && ny >= 0 && nx < M && ny < N) {
			dfs(cnt + 1, ny, nx, sum);
			visited[ny][nx] = 0;
		}
	}
}
int another(int x, int y) {
	int sum = 0;
	int i = x, j = y;
	for (int a = 1; a <= 4; a++) {
				switch (a)
				{
				case 1:
					if (i + 2 < N&&j+1<M)
						sum = poly[i][j] + poly[i + 1][j] + poly[i + 2][j] + poly[i + 1][j + 1];
					if (max < sum) max = sum;
				case 2:
					if (i + 2 < N && j-1 >= 0)
					sum= poly[i][j] + poly[i + 1][j] + poly[i + 2][j] + poly[i + 1][j-1];
					if (max < sum) max = sum;
				case 3:
					if (i +1< N && j +2 <M)
						sum = poly[i][j] + poly[i][j+1] + poly[i+1][j+1] + poly[i][j+2];
					if (max < sum) max = sum;
				case 4:
					if (i -1 >=0 && j + 2 <M)
						sum = poly[i][j] + poly[i][j+1] + poly[i][j+2] + poly[i - 1][j + 1];
					if (max < sum) max = sum;
			}
	}
}
int main(void) {
	while (1) {
		scanf("%d %d", &N, &M);
		max = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &poly[i][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (poly[i][j] > 0) {
					dfs(1, i, j, 0);
				}
				another(i, j);
				visited[i][j] = false;
			}
		}

		printf("%d\n", max);
	}
	return 0;
}