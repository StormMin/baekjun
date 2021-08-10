#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
char a[65][65];
int find(int X, int Y, int N) {
	int cnt = 0;
	int x=Y, y=X;
	bool iscombined=true;
	char tmp = a[x][y];
	for (x=Y; x < N+Y; x++) {
		for (y=X; y < N+X; y++) {
			if (tmp != a[x][y]) {
				iscombined = false;
				break;
			}
		}
		if (iscombined == false) break;
	}
	if (iscombined == true) {
		printf("%c",tmp);
		return;
	}
	printf("(");
		find(X, Y, N / 2);
		find(X+N/2, Y, N / 2);
		find(X, Y+N/2, N / 2);
		find(X + N / 2, Y + N / 2, N / 2);
		printf(")");
}
int main(void) {
	int N,M;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%s", a[i]);
	}
	find(0, 0, N);
}