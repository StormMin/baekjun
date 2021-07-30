#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct king {
	int prior;
	int order;
}king;
int main(void) {
	int N,x,y;
	king a[10000], b[10000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		int max = 0, now = 0, cnt = 1;
		for (int j = 0; j < x; j++) {
			scanf("%d", &a[j].prior);
			a[j].order = j;
		}
		int front=0,rear=x-1;
		while (1) {
			max = 0;
			for (int j = front; j <= rear; j++) {
				if (max < a[j].prior) {
					max = a[j].prior;
					now = j;
				}
			}
			while (front!=now) {
				a[++rear] = a[front++];
			}
			if (a[front].order == y) {
				printf("%d\n", cnt);
				break;
			}
			else {
				front++;
				cnt++;
			}
		}
	}
	return 0;
}