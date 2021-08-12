#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
int N, M;
int minmax(int x,int y) {
	int gcd=1;
	for (int i = 1; i <= x && i <= y; i++) {
		if (x % i == 0 && y % i == 0) {
			gcd = i;
		}
	}
	int lcm = (x * y) / gcd;
	return lcm;
}
int main(void) {
	int T, x, y, a = 1, b = 1, cnt = 0,bnt=0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		bnt = 0;
		scanf("%d %d %d %d", &N, &M, &x, &y);
		a = x;
		b = y;
		cnt = minmax(N, M);
		while (a != b) {
			if (a < b) {
				a += N;
			}
			else {
				b += M;
			}
			if (cnt < a || cnt < b) {
				bnt = 1;
				break;
			}
		}
		if (bnt == 0) printf("%d\n", a);
		else printf("-1\n");
	}
}