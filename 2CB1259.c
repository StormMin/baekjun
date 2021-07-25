#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main() {
	char a[9];
	int j = 0,k=0;
	while (1) {
		k = 0;
		scanf("%s", a);
		if (strcmp(a, "0") == 0) {
			break;
		}
		for (int i = 0; i < strlen(a)/2; i++) {
				j = strlen(a) - i-1;
				if (a[i] == a[j]) {
				}
				else {
					printf("no\n");
					k = 1;
					break;
				}
			}
	if (k == 0) printf("yes\n");
	}
}