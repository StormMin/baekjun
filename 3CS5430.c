#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(void) {
	int T,deq[10001],front = 0,rear=0,N,tmp=0,ts=0;
	char a[1000001],b[1000001];

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%s", a);
		scanf("%d", &N);
		scanf("%s", b);
		int i = 0;
		front = 0;
		rear = 0;
		ts = 0;
		while (N != rear) {
			if (b[i] >= '0' && b[i] <= '9') {
				tmp = tmp*10+b[i] - '0';
				ts = 1;
			}
			else if (ts==1){
				deq[rear++] = tmp;
				tmp = 0;
				ts = 0;
			}
			i++;
		}
		rear--;
		int k = 0;
		front = 0;
		ts = 0;
		for (int j = 0; j < strlen(a); j++) {
			if (a[j] == 'R') {
				if (k == 0) k = 1;
				else if (k == 1) k = 0;
			}
			else if (a[j] == 'D') {
				if (front > rear) {
					printf("error\n");
					ts = 1;
					break;
				}
				if (k == 0) {
					front++;
				}
				else {
					rear--;
				}
			}
		}
		if (ts == 1) continue;
		printf("[");
		if (k == 0) {
			for (int j = front; j <= rear; j++) {
				printf("%d", deq[j]);
				if (j != rear) {
					printf(",");
				}
			}
		}
		if (k == 1) {
			for (int j = rear; j >= front; j--) {
				printf("%d", deq[j]);
				if (j != front) {
					printf(",");
				}
			}
		}
		printf("]\n");
	}
	return 0;
}