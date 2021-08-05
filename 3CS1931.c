#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
typedef struct time {
	int x;
	int y;
}time;
time sorted[100001];
void merge(time a[], int m, int middle, int n) {
	int i = m, j = middle + 1, k = m;
	while (i <= middle && j <= n) {
		if (a[i].y < a[j].y) {
			sorted[k] = a[i];
			i++;
		}
		else if (a[i].y>a[j].y) {
			sorted[k] = a[j];
			j++;
		}
		else {
			if (a[i].x < a[j].x) {
				sorted[k] = a[i];
				i++;
			}
			else {
				sorted[k] = a[j];
				j++;
			}
		}
		k++;
	}
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}
void mergeSort(time a[], int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main(void) {
	int N,x,tmp,cnt=0,a=1000,b;
	time c[100001];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &c[i].x, &c[i].y);
		
	}
	mergeSort(c, 0, N - 1);
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			cnt++;
			tmp = c[i].y;
		}
		else {
			if (c[i].x >= tmp) {
				cnt++;
				tmp = c[i].y;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}