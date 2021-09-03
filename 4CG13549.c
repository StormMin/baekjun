#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int q[10000111], front = -1, rear = -1;
int d[10000111];
bool v[100001];
int main()
{
	int x, k,min=999999,w=999999;
	scanf("%d %d", &x, &k);
	q[++rear] = x;
	d[rear] = 0;
	v[x] = true;
	while (front != rear) {
		front++;
		v[q[front]] = true;
		if (q[front] == k) {
			v[k] = false;
			if (w > d[front]) {
				w = d[front];
			}
		}
		if (q[front] - 1 >= 0 && !v[q[front] - 1]&&min>d[front]) {
			q[++rear] = q[front] - 1;
			d[rear] = d[front] + 1;
		}
		if (q[front] + 1 < 2 * k && !v[q[front] + 1] && min > d[front]) {
			q[++rear] = q[front] + 1;
			d[rear] = d[front] + 1;
		}
		if (q[front] * 2 < 2 * k && !v[q[front] * 2] && min >= d[front]) {
			q[++rear] = q[front]*2;
			d[rear] = d[front];
		}
	}
	printf("%d", w);
	return 0;
}