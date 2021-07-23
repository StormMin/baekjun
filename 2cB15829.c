#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, M, i = 1, j = 1,k,max=0;
	char  a;
	long long tmp=1,result=0;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%c", &a);
		k = a - 'a'+1;
		result += (k * tmp)%1234567891;
		tmp *= 31;
		tmp %= 1234567891;
	}
	result %= 1234567891;
	printf("%lld", result);

}