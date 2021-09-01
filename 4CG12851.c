#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int q[1000011], front = -1, rear = -1;
int d[1000011];
bool v[100001];
int main() {
	int N, K, cnt = 0, min = 999999, a = 0, b, c;
	scanf("%d %d", &N, &K);
	q[++rear] = N;
	d[rear] = 0;
	while (front != rear) {
		front++;
		v[q[front]] = true;
		if (q[front] == K) {
			if (cnt == 0) {
				min = d[front];
			}
			if (min == d[front]) {
				cnt++;
			}
		}
		if (q[front] - 1 >= 0 && d[front] < min && !v[q[front] - 1]) {
			q[++rear] = q[front] - 1;
			d[rear] = d[front] + 1;
		}
		if (q[front] + 1 < 2 * K && d[front] < min && !v[q[front] + 1]) {
			q[++rear] = q[front] + 1;
			d[rear] = d[front] + 1;

		}
		if (q[front] * 2 < 2 * K && d[front] < min && !v[q[front] * 2]) {
			q[++rear] = q[front] * 2;
			d[rear] = d[front] + 1;

		}
	}
	printf("%d\n%d", min, cnt);
	return 0;

}