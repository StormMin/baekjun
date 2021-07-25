#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
int main(void) {
	int N, a, b = 0, c = 0;
	scanf("%d", &N);
	while (N != 0) {
		if (N >= 15) {
			N -= 5;
			c++;
		}
		else if ((N - 3) % 5 == 0) {
			N -= 3;
			c++;
		}
		else if ((N - 5) % 3 == 0) {
			N -= 5;
			c++;
		}
		else if (N % 5 == 0) {
			N -= 5;
			c++;
		}
		else if (N % 3 == 0) {
			N -= 3;
			c++;
		}
		else {
			b = 1;
			break;
		}
	}
	if (b == 1) printf("-1");
	else	printf("%d", c);
}