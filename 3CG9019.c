#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
bool visited[10000];
typedef struct queue {
	int num;
	char i[100];
}queue;
int D(int x) {
	return (x * 2) % 10000;
	}
int S(int x) {
	if (x == 0) {
		return 9999;
	}
	else return x - 1;
}
int L(int x) {
	return (x % 1000) * 10 + (x / 1000);
}
int R(int x) {
	return (x % 10) * 1000 + (x / 10);
}
queue q[10000];
int d[10000];
int front=-1,rear=-1,A,B;
int bfs() {
	int Dmp,Smp,Lmp,Rmp;
	q[++rear].num = A;
	visited[A] = 1;
	d[rear] = 0;
	while (front != rear) {
		++front;
		Dmp = D(q[front].num);
		Smp = S(q[front].num);
		Lmp = L(q[front].num);
		Rmp = R(q[front].num);
		if (visited[Dmp] == 0) {
			visited[Dmp] = 1;
			q[++rear].num = Dmp;
			d[rear] = d[front] + 1;
			for (int j = 0; j < d[rear]-1; j++) {
				q[rear].i[j] = q[front].i[j];
			}
			q[rear].i[d[rear]-1] = 'D';
		}
		if (q[rear].num == B) break;

		if (visited[Smp] == 0) {
			visited[Smp] = 1;
			q[++rear].num = Smp;
			d[rear] = d[front] + 1;
			for (int j = 0; j < d[rear]-1; j++) {
				q[rear].i[j] = q[front].i[j];
			}
			q[rear].i[d[rear] - 1] = 'S';
		}
		if (q[rear].num == B) break;

		if (visited[Lmp] == 0) {
			visited[Lmp] = 1;
			q[++rear].num = Lmp;
			d[rear] = d[front] + 1;
			for (int j = 0; j < d[rear] - 1; j++) {
				q[rear].i[j] = q[front].i[j];
			}
			q[rear].i[d[rear] - 1] = 'L';
		}
		if (q[rear].num == B) break;

		if (visited[Rmp] == 0) {
			visited[Rmp] = 1;
			q[++rear].num = Rmp;
			d[rear] = d[front] + 1;
			for (int j = 0; j < d[rear] - 1; j++) {
				q[rear].i[j] = q[front].i[j];
			}
			q[rear].i[d[rear] - 1] = 'R';
		}
		if (q[rear].num == B) break;
	}
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int j = 0; j < T; j++) {
		scanf("%d %d", &A, &B);
		front = -1; rear = -1;
		memset(visited, false, sizeof(visited));
		bfs();
		for (int k = 0; k < d[rear]; k++) {
			printf("%c", q[rear].i[k]);
		}
		printf("\n");
	}
	return 0;
}