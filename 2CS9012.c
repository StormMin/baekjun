#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	char a[101], b[101] = { 0 };
	int i = 0,k=0;
	int N;
	scanf("%d", &N);
	getchar();
	for (int p = 0; p < N;p++) {
		i = -1;
		k = 0;
		gets(a);
		for (int j = 0; j < strlen(a); j++) {
			if (a[j] == '(' || a[j] == '[') {
				i++;
				b[i] = a[j];
			}
			else if (a[j] == ')') {
				if (b[i] == '(') {
					i--;
				}
				else {
					k = 1;
					break;
				}
			}
			else if (a[j] == ']') {
				if (b[i] == '[') {
					i--;
				}
				else {
					k = 1;
					break;
				}
			}
		}
			if (k == 0 && i == -1) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
	}
	return 0;
}