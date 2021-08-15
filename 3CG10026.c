#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
bool visited[101][101];
char RGB[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int N;
int Blue;
int count;
int dfs(char c,int x,int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N && RGB[nx][ny] == c&&visited[nx][ny]==0) {
			dfs(c, nx, ny);
		}
	}
}
int dfsRG(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N && (RGB[nx][ny] == 'R'||RGB[nx][ny]=='G') && visited[nx][ny] == 0) {
			dfsRG(nx, ny);
		}
	}
}
int main(void) {
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%c", &RGB[i][j]);
		}
		getchar();
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				if (RGB[i][j] == 'R') {
					dfs(RGB[i][j], i, j);
					count++;
				}
				else if (RGB[i][j] == 'G') {
					dfs(RGB[i][j], i, j);
					count++;
				}
				else if (RGB[i][j] == 'B') {
					dfs(RGB[i][j], i, j);
					count++;
					Blue++;
				}
			}
		}
	}
	printf("%d ", count);
	count = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((RGB[i][j] == 'R'|| RGB[i][j] == 'G')&&visited[i][j]==0) {
				dfsRG(i, j);
				count++;
			}
		}
	}
	printf("%d", (Blue + count));
	return 0;
}