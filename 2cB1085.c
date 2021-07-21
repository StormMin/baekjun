#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int a[4];
	scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
	int e = a[0] - a[2];
	int f = a[1] - a[3];
	if (e < 0) e = -e;
	if (f < 0) f = -f;
	a[2] = e;
	a[3] = f;
	for (int i = 0; i < 3; i++) {
		for (int j = i; j < 4; j++) {
			if (a[i] > a[j]) {
				int tnp = a[i];
				a[i] = a[j];
				a[j] = tnp;
			}
		}
	}
	printf("%d", a[0]);
	return 0;
}