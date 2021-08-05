#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	int N,i,j=0,sum=0,tmp=0,k=0;
	char a[51];
	int it[51];
	scanf("%s", a);
	for ( i = 0; i <= strlen(a); i++) {
		if (a[i] == '-'||i==strlen(a)) {
			sum = sum + tmp;
			it[k] = sum;
			k++;
			tmp = 0;
			sum = 0;
		}
		else if (a[i] == '+') {
			sum = sum + tmp;
			tmp = 0;
		}
		else {
			tmp = tmp * 10;
			tmp += a[i] - '0';
		}
	}
	for (i = 1; i < k; i++) {
		it[0] -= it[i];
	}
	printf("%d", it[0]);
	return 0;
}