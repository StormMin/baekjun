#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int los[101];
int q[10001], front = -1, rear = -1;
int d[10001];
int bfs() {
	int x = 1;
	q[++rear] = 1;
	d[1] = 0;
	while (front != rear) {
		front++;
		x = q[front];
		for (int i = 1; i <= 6; i++) {
			int nx = x + i;
			if (nx > 100) continue;
			if (los[nx] != 0) {
				nx = los[nx];
			}
			if (d[nx] == 0) {
				d[nx] = d[x] + 1;
				q[++rear] = nx;
			}
		}
	}
}
int main(void) {
	int N, M,x,y;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N + M; i++) {
		scanf("%d %d", &x,&y);
		los[x] = y;
	}
	bfs();
	printf("%d", d[100]);
	return 0;
}