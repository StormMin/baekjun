#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int bun(int N) {
	if (N < 10) return N;
	int tmp = N % 10;
	int sum = tmp + bun(N / 10);
	return sum;
}
int main() {
	int N,tmp,k=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		tmp = i + bun(i);
		if (tmp == N) {
			k = 1;
			printf("%d", i);
			break;
		}
	}
	if (k == 0) printf("0");
	return 0;
}