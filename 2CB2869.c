#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
int main(void) {
	int A, B, C, car = 0, tmp = 0;
	scanf("%d %d %d", &A, &B, &C);
	if (A == C) {
		printf("1");
	}
	else {
		tmp = (C-A) / (A - B);
		car = (C - A) % (A - B);
		if (car != 0) {
			tmp += 2;
		}
		else tmp++;
		printf("%d", tmp);
	}

	return 0;
}