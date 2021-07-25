#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
int factor(int N) {
	int tmp=1;
	if (N == 1) return 1;
	return factor(N - 1) * N; 
}
int main(void) {
	int A, B,C;
	scanf("%d %d", &A, &B);
	C = A - B;
	if (A == B) printf("1");
	else
	printf("%d", factor(A) / (factor(C) * (factor(B))));
	return 0;
}