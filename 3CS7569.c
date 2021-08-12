#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
int N, M, H;
int qx[1000000], qy[1000000], qz[1000000],front=-1,rear=-1;
int visit[101][101][101];
int box[101][101][101];
int d[1000000];
int bfs() {
	while (front != rear) {
		++front;
		if (qx[front] + 1 >= 0 && qx[front] + 1 < M) {
			if (box[qz[front]][qx[front] + 1][qy[front]] >= 0 && visit[qz[front]][qx[front] + 1][qy[front]] == 0) {
				qx[++rear] = qx[front] + 1;
				qy[rear] = qy[front];
				qz[rear] = qz[front];
				if (box[qz[rear]][qx[rear]][qy[rear]] == 1) {
					d[rear] = d[front];
				}
				else
					d[rear] = d[front] + 1;
				visit[qz[rear]][qx[rear]][qy[rear]] = 1;
			}
		}
		if (qx[front] - 1 >= 0 && qx[front] - 1 < M) {
			if (box[qz[front]][qx[front] - 1][qy[front]] >= 0 && visit[qz[front]][qx[front] - 1][qy[front]] == 0) {
				qx[++rear] = qx[front] - 1;
				qy[rear] = qy[front];
				qz[rear] = qz[front];
				if (box[qz[rear]][qx[rear]][qy[rear]] == 1) {
					d[rear] = d[front];
				}
				else
					d[rear] = d[front] + 1;
				visit[qz[rear]][qx[rear]][qy[rear]] = 1;
			}
		}
		if (qy[front] + 1 >= 0 && qy[front] + 1 < N) {
			if (box[qz[front]][qx[front]][qy[front] + 1] >= 0 && visit[qz[front]][qx[front]][qy[front] + 1] == 0) {
				qx[++rear] = qx[front];
				qy[rear] = qy[front] + 1;
				qz[rear] = qz[front];
				if (box[qz[rear]][qx[rear]][qy[rear]] == 1) {
					d[rear] = d[front];
				}
				else
					d[rear] = d[front] + 1;
				visit[qz[rear]][qx[rear]][qy[rear]] = 1;
			}
		}
		if (qy[front] - 1 >= 0 && qy[front] - 1 < N) {
			if (box[qz[front]][qx[front]][qy[front] - 1] >= 0 && visit[qz[front]][qx[front]][qy[front] - 1] == 0) {
				qx[++rear] = qx[front];
				qy[rear] = qy[front] - 1;
				qz[rear] = qz[front];
				if (box[qz[rear]][qx[rear]][qy[rear]] == 1) {
					d[rear] = d[front];
				}
				else
					d[rear] = d[front] + 1;
				visit[qz[rear]][qx[rear]][qy[rear]] = 1;
			}
		}
		if (qz[front] + 1 >= 0 && qz[front] + 1 < H) {
			if (box[qz[front] + 1][qx[front]][qy[front]] >= 0 && visit[qz[front] + 1][qx[front]][qy[front]] == 0) {
				qx[++rear] = qx[front];
				qy[rear] = qy[front];
				qz[rear] = qz[front] + 1;
				if (box[qz[rear]][qx[rear]][qy[rear]] == 1) {
					d[rear] = d[front];
				}
				else
					d[rear] = d[front] + 1;
				visit[qz[rear]][qx[rear]][qy[rear]] = 1;
			}
		}
		if (qz[front] - 1 >= 0 && qz[front] - 1 < H) {
			if (box[qz[front] - 1][qx[front]][qy[front]] >= 0 && visit[qz[front] - 1][qx[front]][qy[front]] == 0) {
				qx[++rear] = qx[front];
				qy[rear] = qy[front];
				qz[rear] = qz[front] - 1;
				if (box[qz[rear]][qx[rear]][qy[rear]] == 1) {
					d[rear] = d[front];
				}
				else
					d[rear] = d[front] + 1;
				visit[qz[rear]][qx[rear]][qy[rear]] = 1;
			}
		}
	}
}
int main() {
	scanf("%d %d %d", &N, &M, &H);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				scanf("%d", &box[i][j][k]);
				if (box[i][j][k] == -1) visit[i][j][k] = 1;
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (box[i][j][k] == 1) {
					qx[++rear] = j;
					qy[rear] = k;
					qz[rear] = i;
					d[rear] = 1;
					visit[i][j][k] = 1;
				}
			}
		}
	}
	bfs();
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (visit[i][j][k] == 0) {
					printf("-1");
					return 0;
				}
			}
		}
	}
	printf("%d", d[rear] - 1);
}