#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long los[12];
int main(void) {
	long long bk,tmp,cnt,num=1,M,ans=100,k=0,stop=0;
	long long N;
	scanf("%lld", &N);
	getchar();
	scanf("%lld", &bk);
	for (int i = 0; i < bk; i++) {
		scanf("%lld", &tmp);
		los[tmp] = 1;
	}
	M = N;
	cnt = abs(100 - M);
	ans = M;
	int but = 0;
	if (bk != 10) {
		while (1) {
			num = 1000000;
			if (M <= 0) {
				if (M == 0) {
					if (los[0] == 0) break;
				}
				stop = 1;
				break;
			}
			tmp = M;
			long long num1;
			while (1) {
				if (tmp / num > 0) {
					num1 = num;
					break;
				}
				else num /= 10;
			}
			k = 0;
			while (num1 != 0) {
				if (los[tmp / num1] == 1) {
					M -= num1;
					M =M+(num1 - M % num1 - 1);
					k = 1;
					break;
				}
				else {
					tmp %= num1;
					num1 /= 10;
				}
			}
			if (k == 0) break;
		}
		for (int i = 0; i <= 1000000; i *= 10) {
			if (M >= i) {
				but++;
			}
			if (i == 0) i++;
		}
		if (stop != 1) {
			if (cnt > abs(ans - M) + but) {
				cnt = abs(ans - M) + but;
			}
		}
		M = ans;
		while (1) {
			num = 1000000;
			tmp = M;
			long long num1;
			if (M == 0) {
				if (los[0] == 0) break;
			}
			while (1) {
				if (tmp / num > 0) {
					num1 = num;
					break;
				}
				else num /= 10;
			}
			long long num2 = num1;
			k = 0;
			while (num1 != 0) {
				if (los[tmp / num1] == 1) {
					M += num1;
					M = M - (M % num1);
					k = 1;
					break;
				}
				else {
					tmp %= num1;
					num1 /= 10;
				}
			}
			if (k == 0) break;
		}
		but = 0;
		for (int i = 0; i <= 1000000; i *= 10) {
			if (M >= i) {
				but++;
			}
			if (i == 0) i++;
		}
		if (cnt > abs(ans - M) + but) {
			cnt = abs(ans - M) + but;
		}
	}
	printf("%lld", cnt);
	return 0;
}