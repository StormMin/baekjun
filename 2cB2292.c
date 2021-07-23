#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, M,tmp=1,i=1,j=1;
	scanf("%d", &N);
	while (N > i) {
		i = i + 6 * j;
		j++;
		tmp++;
	}
	printf("%d", tmp);
	return 0;
}