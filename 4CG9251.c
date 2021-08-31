#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int Table[1004][1004];
int MAX(int a, int b) {
	if (a < b) return b;
	return a;
}
int main()
{
	char a[1000],b[1000];
	scanf("%s", a);
	scanf("%s", b);
	int x = strlen(a);
	int y = strlen(b);
	int i, j;
	for (i = 1; i <= x; i++) {
		for (j = 1; j <= y; j++) {
			if (a[i-1] == b[j-1]) {
				Table[i][j] = Table[i - 1][j - 1] + 1;
			}
			else {
				Table[i][j] = MAX(Table[i - 1][j], Table[i][j - 1]);
			}
		}
	}
	printf("%d", Table[x][y]);
	return 0;
}
