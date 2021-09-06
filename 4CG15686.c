#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int N, M;
int a[51][51];
bool v[13];
int INF = 987654321;
typedef struct {
	int y, x;
}dir;
dir h[101],c[13],r[13];
int hsize, csize,rsize;
int distance(dir x,dir y) {
	return abs(x.y-y.y) + abs(x.x - y.x);
}
int real=987654321;
void DFS() {
	int result=0;
	for (int i = 0; i < hsize; i++) {
		int p,min = INF;
		for (int j = 0; j < rsize; j++) {
			p = distance(h[i], r[j]);
			if (p < min) {
				min = p;
			}
	}
		result += min;
	}
	if (result < real) {
		real = result;
	}
}
void find(int cnt,int t) {
	if (cnt == M) {
		DFS();
		return;
	}
	for (int i = t; i < csize; i++) {
		if (!v[i]) {
				r[rsize].x = c[i].x;
				r[rsize++].y = c[i].y;
				v[i] = 1;
				find(cnt + 1,i);
				v[i] = 0;
				rsize--;
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1) {
				h[hsize].x = j;
				h[hsize++].y = i;
			}
			if (a[i][j] == 2) {
				c[csize].x = j;
				c[csize++].y = i;
			}
		}
	}
	find(0,0);
	printf("%d", real);
	return 0;
}