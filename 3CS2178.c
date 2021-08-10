#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
int a[101][101];
int visit[101][101],x,y;
int qx[200],qy[200],d[200],front=-1,rear=-1;
int main(void) {
	int N, M;
	char b[101][101];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", b[i]);
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j] - '0';
		}
	}
	qx[++rear] = 0;
	qy[rear] = 0;
	visit[0][0] = 1;
	d[rear] = 1;
	while (front != rear) {
		front++;
		if (a[qx[front]+1][qy[front]] == 1 && visit[qx[front] + 1][qy[front]] == 0) {
			qx[++rear] = qx[front]+1;
			qy[rear] = qy[front];
			d[rear] = d[front] + 1;
			visit[qx[rear]][qy[rear]] = 1;
		}
		if (N-1 == qx[rear] && qy[rear] == M-1) break;

		if (a[qx[front] - 1][qy[front]] == 1 && visit[qx[front] - 1][qy[front]] == 0) {
			qx[++rear] = qx[front] - 1;
			qy[rear] = qy[front];
			d[rear] = d[front] + 1;
			visit[qx[rear]][qy[rear]] = 1;
		}
		if (N - 1 == qx[rear] && qy[rear] == M - 1) break;

		if (a[qx[front]][qy[front]+1] == 1 && visit[qx[front]][qy[front]+1] == 0) {
			qx[++rear] = qx[front];
			qy[rear] = qy[front]+1;
			d[rear] = d[front] + 1;
			visit[qx[rear]][qy[rear]] = 1;
		}
		if (N - 1 == qx[rear] && qy[rear] == M - 1) break;

		if (a[qx[front]][qy[front]-1] == 1 && visit[qx[front]][qy[front]-1] == 0) {
			qx[++rear] = qx[front];
			qy[rear] = qy[front]-1;
			d[rear] = d[front] + 1;
			visit[qx[rear]][qy[rear]] = 1;
		}
		if (N - 1 == qx[rear] && qy[rear] == M - 1) break;
	}
	printf("%d", d[rear]);
}