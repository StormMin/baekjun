#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	int stick;
	scanf("%d", &stick);
	int cnt = 0;
	for (; stick > 0; stick = stick / 2) {
		if (stick % 2 == 1) cnt++;
	}
	printf("%d", cnt);
	return 0;
}