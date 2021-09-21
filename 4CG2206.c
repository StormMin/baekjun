#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int map[1001][1001],N,M;
char dup[1001][1001];
bool visited[1001][1001][2];
typedef struct {
	int y, x;
}mo;
mo moveD[4] = { {1,0},{0,1} ,{-1,0} ,{0,-1} };
typedef struct {
	int y, x, k;
}queue; 
queue q[6000000];
int d[6000000];
int front = -1, rear = -1;
int main() {
	scanf("%d %d", &N, &M);
	getchar();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%c", &dup[i][j]);
		}
		getchar();
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			map[i][j] = dup[i][j] - '0';
		}
	}
	q[++rear].y = 1;
	q[rear].x = 1;
	d[rear] = 1;
	while (front != rear) {
		++front;
		for (int i = 0; i < 4; i++) {
			int nextX = q[front].x + moveD[i].x;
			int nextY = q[front].y + moveD[i].y;
			if (nextX > M || nextY > N || nextX < 1 || nextY < 1) {
				continue;
			}
			if (map[nextY][nextX] == 1 && q[front].k == 1) {
				continue;
			}
			if (q[front].k == 1) {
				if (!visited[nextY][nextX][1]) {
					q[++rear].x = nextX;
					q[rear].y = nextY;
					d[rear] = d[front] + 1;
					q[rear].k = 1;
					visited[nextY][nextX][1] = 1;
				}
			}
			else {
				if (!visited[nextY][nextX][0]) {
					q[++rear].x = nextX;
					q[rear].y = nextY;
					d[rear] = d[front] + 1;
					if (map[nextY][nextX] == 1) {
						q[rear].k = 1;
						visited[nextY][nextX][1] = 1;
					}
					else {
						q[rear].k = 0;
						visited[nextY][nextX][0] = 1;
						visited[nextY][nextX][1] = 1;
					}
				}
			}
			if (nextY == N && nextX == M) {
				printf("%d", d[rear]);
				return 0;
			}
		}
	}
	if (q[rear].x == M && q[rear].y == N) {
		printf("%d", d[rear]);
	}
	else
	printf("-1");
	return 0;
}