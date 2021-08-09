#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N, K, L, Q[250000], visit[100001], front = -1, rear = -1, count, token;
int d[100001];
int main(void) {
	scanf("%d %d", &N, &K);
	if (N == K) {
		printf("0");
		return 0;
	}
	Q[++rear] = N;
	while (front != rear) {
		count++;
		front++;
		if (visit[Q[front] * 2] == 0 && (Q[front] * 2) < 100001 && Q[front] * 2 >= 0) {
			Q[++rear] = Q[front] * 2;
			d[rear] = d[front] + 1;
			visit[Q[rear]] = 1;
		}
		if (Q[rear] == K) {
			break;
		}
		if (visit[Q[front]-1] == 0 && (Q[front] -1) < 100001 && Q[front] -1 >= 0) {
			Q[++rear] = Q[front] -1;
			d[rear] = d[front] + 1;
			visit[Q[rear]] = 1;
		}
		if (Q[rear] == K) {
			break;
		}
		if (visit[Q[front] +1] == 0 && (Q[front] +1) < 100001 && Q[front] +1 >= 0) {
			Q[++rear] = Q[front] +1;
			d[rear] = d[front] + 1;
			visit[Q[rear]] = 1;
		}
		if (Q[rear] == K) {
			break;
		}
	}
	printf("%d", d[rear]);
	return 0;
}