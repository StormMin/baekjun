#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int N,a,b,c,cnt=0,k,j,i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		cnt = 0;
		scanf("%d %d %d", &a, &b, &c);
		for (j = 1; j <= b; j++) {
			for ( k = 1; k <= a; k++) {
				cnt++;
				if (cnt == c) {
					break;
				}
			}
			if (cnt == c) break;
		}
		if (j > 9) printf("%d%d\n", k, j);
		else printf("%d0%d\n", k, j);
	}
	return 0;
}