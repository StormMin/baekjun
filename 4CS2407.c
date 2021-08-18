#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
typedef struct {
	char a[100];
}string;
string c[100][100];
string add(string x, string y) {
	long long sum = 0;
	string result;
	int i = strlen(x.a) - 1, j = strlen(y.a) - 1,k=0;
	while (i >= 0 || j >= 0||sum>0) {
		if (i >= 0) {
			sum += x.a[i] - '0';
			i--;
		}
		if (j >= 0) {
			sum += y.a[j] - '0';
			j--;
		}
		result.a[k++] = (sum % 10 + '0');
		sum /= 10;
	}
	for (int i = 0; i < k/2; i++) {
		char tmp = result.a[i];
		result.a[i] = result.a[k - i - 1];
		result.a[k - i - 1] = tmp;
	}
	result.a[k] = '\0';
	return result;
}
string combi(int x, int p) {
	if (x == p || p == 0) {
		c[x][p].a[0] = '1';
		c[x][p].a[1] = '\0';
		return c[x][p];
	}
	string z = combi(x - 1, p - 1)
		, zz = combi(x - 1, p);
	strcpy(c[x][p].a,add(z,zz).a);
	return c[x][p];
}
int main(void) {
	int x, p;
	scanf("%d %d", &x, &p);
	combi(x, p);
	printf("%s", c[x][p].a);
	return 0;
}