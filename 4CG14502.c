#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
typedef struct {
	int y, x;
}queue;
queue q[100001];
int N, M,max;
int Map[8][8],temp[8][8];
int front=-1,rear=-1;
typedef struct{
	int y, x;
}Dir;
Dir moveDir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
void BFS() {
	int a[8][8];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = temp[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] == 2) {
				q[++rear].y = i;
				q[rear].x = j;
			}
		}
	}
	while (front != rear) {
		front++;
		int x = q[front].x;
		int y = q[front].y;
		for (int i = 0; i < 4; i++) {
			int nextX = x + moveDir[i].x;
			int nextY = y + moveDir[i].y;
			if (nextX >= 0 && nextY >= 0 && nextX < M && nextY < N && a[nextY][nextX] == 0) {
				a[nextY][nextX] = 2;
				q[++rear].x = nextX;
				q[rear].y = nextY;
			}
		}
	}
	int empty = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] == 0) {
				empty++;
			}
		}
	}
	if (max < empty) {
		max = empty;
	}
	rear = -1;
	front = -1;
}
void makewall(int cnt) {
	if (cnt == 3) {
		BFS();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0) {
				temp[i][j] = 1;
				makewall(cnt + 1);
				temp[i][j] = 0;
			}
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &Map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 0) {
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < M; l++) {
						temp[k][l] = Map[k][l];
					}
				}
				temp[i][j] = 1;
				makewall(1);
				temp[i][j] = 0;
			}
		}
	}
	printf("%d", max);
	return 0;
}