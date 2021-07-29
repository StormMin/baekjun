#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long binary_find(long long a[], long long n,long long max, long long k) {
    int low, high, mid;
    low = 1;
    high = max;
    
    while (low <= high) {
        int cnt = 0;
        mid = (low + high) / 2;
        for (int j = 0; j < n; j++) {
            cnt += a[j] / mid;
        }
        if (cnt < k) {
            high = mid - 1;
        }
        else if (cnt >= k) {
            low = mid + 1;
        }
    }
    return high;
}
int main(void) {
	long long N, M,a[10000],max=0,i;
	scanf("%lld %lld", &N, &M);
	for (i=0;i<N;i++){
		scanf("%lld", &a[i]);
        if (max < a[i]) max = a[i];
	}
    printf("%lld", binary_find(a, N, max, M));
	return 0;
}