#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
long long d[100000];
bool visited[100000];
long long q[100000], front = -1, rear = -1;
int main()
{
	long long A, B;
	scanf("%lld %lld", &A, &B);
	q[++rear] = A;
	d[rear] = 1;
	visited[q[rear]] = 1;
	while (front != rear) {
		front++;
		if (visited[q[front] * 10 + 1] == 0 && q[front] * 10 + 1 <= B) {
			q[++rear] = q[front] * 10 + 1;
			d[rear] = d[front] + 1;
			visited[q[rear]] = 1;
		}
		if (q[rear] == B) {
			printf("%lld", d[rear]);
			return 0;
		}
		if (visited[q[front] * 2] == 0 && q[front] * 2 <= B) {
			q[++rear] = q[front] * 2;
			d[rear] = d[front] + 1;
			visited[q[rear]] = 1;
		}
		if (q[rear] == B) {
			printf("%lld", d[rear]);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
