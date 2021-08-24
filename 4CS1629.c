#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int fun(int a,int b,int c) {
	if (b > 1) {
		long long result = fun(a, b / 2, c);
		if (b % 2 == 0) return (result * result)%c;
		else {
			return ((result * result)%c * a) % c;
		}
	}
	else return a;
}
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", fun(a%c, b, c));
	return 0;
}
