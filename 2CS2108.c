#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sum(int a[], int n) {
	double temp=0;
	for (int i = 0; i < n; i++) {
		temp += a[i];
	}
	printf("%.0lf\n", temp/n);
}
int mid(int a[], int n) {
	printf("%d\n", a[n / 2]);
}
int crowd(int a[], int n) {
	int cnt=0, bnt=0,k=0,tmp=0,max=0,i,b=0;
	for ( i = 0; i < n; i++) {
		if (i == 0) {
			cnt = a[i];
			k++;
		}
		else if (cnt == a[i]) {
			k++;
		}
		else {
			if (k > max) {
				tmp=i-1;
				max = k;
				b = 0;
			}
			else if (k == max&&b==0) {
				b = i - 1;
			}
			k = 1;
			cnt = a[i];
		}
	}
	if (k > max) {
		tmp = i - 1;
		max = k;
	}
	else if (k == max&&b==0) {
		b = i - 1;
	}
	if (b == 0)
		printf("%d\n", a[tmp]);
	else printf("%d\n", a[b]);
}
int maxmin(int a[], int n) {
	printf("%d", a[n - 1] - a[0]);
}
int main(void) {
	int N;
	int a[1000001];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < N; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (a[root] < a[c]) {
				int temp = a[root];
				a[root] = a[c];
				a[c] = temp;
			}
			c = root;
		} while (c!=0);
	}
	for (int i = N - 1; i >= 0; i--) {
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		int root = 0;
		int c = 1;
		do {
			c = root * 2 + 1;
			if (a[c] < a[c + 1] && c < i - 1) {
				c++;
			}
			if (a[c] > a[root] && c < i) {
				int temp = a[root];
				a[root] = a[c];
				a[c] = temp;
			}
			root = c;
		} while (c<i);
	}
	
	sum(a, N);
	mid(a, N);
	crowd(a, N);
	maxmin(a, N);
	return 0;
}