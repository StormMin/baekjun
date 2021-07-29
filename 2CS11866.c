#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[1001];
int main(void) {
	int N, M,k=0,i=1,cnt=0;
	scanf("%d %d", &N, &M);
	printf("<");
		while (1) {
			if (i > N) i = 1;
			if (a[i] != 0) {
				i++;
				continue;
			}
			else {
				k++;
				if (k == M) {
					printf("%d", i);
					cnt++;
					if (cnt != N) printf(", ");
					a[i] = 1;
					k = 0;
				}
			}
			if (cnt == N) break;
			i++;
		}
		printf(">");
	return 0;
}