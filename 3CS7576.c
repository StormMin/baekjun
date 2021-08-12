#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
int N, M;
int qx[1000000], qy[1000000],front=-1,rear=-1;
int visit[101][101];
int box[101][101];
int d[1000000];
int bfs() {
	while (front != rear) {
		++front;
		if (qx[front] + 1 >= 0 && qx[front] + 1 < M) {
			if (box[qx[front] + 1][qy[front]] >= 0 && visit[qx[front] + 1][qy[front]] == 0) {
				qx[++rear] = qx[front] + 1;
				qy[rear] = qy[front];
				if (box[qx[rear]][qy[rear]] == 1) {
					d[rear] = d[front];
				}
				else
					d[rear] = d[front] + 1;
				visit[qx[rear]][qy[rear]] = 1;
			}
		}
		if (qx[front] - 1 >= 0 && qx[front] - 1 < M) {
			if (box[qx[front] - 1][qy[front]] >= 0 && visit[qx[front] - 1][qy[front]] == 0) {
				qx[++rear] = qx[front] - 1;
				qy[rear] = qy[front];
				if (box[qx[rear]][qy[rear]] == 1) {
					d[rear] = d[front];
				}
				else
					d[rear] = d[front] + 1;
				visit[qx[rear]][qy[rear]] = 1;
			}
		}
		if (qy[front] + 1 >= 0 && qy[front] + 1 < N) {
			if (box[qx[front]][qy[front] + 1] >= 0 && visit[qx[front]][qy[front] + 1] == 0) {
				qx[++rear] = qx[front];
				qy[rear] = qy[front] + 1;
				if (box[qx[rear]][qy[rear]] == 1) {
					d[rear] = d[front];
				}
				else
					d[rear] = d[front] + 1;
				visit[qx[rear]][qy[rear]] = 1;
			}
		}
		if (qy[front] - 1 >= 0 && qy[front] - 1 < N) {
			if (box[qx[front]][qy[front] - 1] >= 0 && visit[qx[front]][qy[front] - 1] == 0) {
				qx[++rear] = qx[front];
				qy[rear] = qy[front] - 1;
				if (box[qx[rear]][qy[rear]] == 1) {
					d[rear] = d[front];
				}
				else
					d[rear] = d[front] + 1;
				visit[qx[rear]][qy[rear]] = 1;
			}
		}
		
	}
}
int main() {
	scanf("%d %d", &N, &M);
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				scanf("%d", &box[j][k]);
				if (box[j][k] == -1) visit[j][k] = 1;
			}
		}
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (box[j][k] == 1) {
					qx[++rear] = j;
					qy[rear] = k;
					d[rear] = 1;
					visit[j][k] = 1;
				}
			}
		}
	bfs();

		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (visit[j][k] == 0) {
					printf("-1");
					return 0;
				}
			}
	}
	printf("%d", d[rear] - 1);
}