#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long binary_find(long long a[],long long N,long long M, long long max) {
	long long i,low=0, mid, high=max,cnt=0;
	while (low <= high) {
		mid = (low + high) / 2;
		cnt = 0;
		for (i = 0; i < N; i++) {
			if (a[i] - mid > 0) {
				cnt += a[i] - mid;
			}
		}
		if (cnt < M) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return high;
}
int main(void) {
	long long N, M,a[10000],max=0;
	scanf("%lld %lld", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
		if (max < a[i]) {
			max = a[i];
		}
	}
	printf("%lld",binary_find(a, N, M, max));

	return 0;
}