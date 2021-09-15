#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
long long N, E;
long long INF = 986754321;
bool dis[1000], vs[801][801];
long long d[801],Graph[801][801];
int getSmall() {
	int index=1;
	long long min = INF;
	for (int i = 1; i <= N; i++) {
		if (!dis[i] && d[i] < min) {
			min = d[i];
			index = i;
		}
	}
	return index;
}
int dij(int x) {
	for (int i = 1; i <= N; i++) {
		d[i] = Graph[x][i];
	}
	dis[x] = 1;
	for (int i = 1; i <= N-2; i++) {
		int current = getSmall();
		dis[current] = 1;
		for (int j = 1; j <= N; j++) {
				if (d[current] + Graph[current][j] < d[j]) {
					d[j] = d[current] + Graph[current][j];
			}
		}
	}

}
int main(){
	scanf("%lld %lld", &N, &E);
	int x, y,v1,v2;
	long long e;
	for (long long i = 1; i <= E; i++) {
		scanf("%d %d %lld", &x, &y, &e);
		Graph[x][y] = e;
		Graph[y][x] = e;
		vs[x][y] = 1;
		vs[y][x] = 1;
	} 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j && !vs[i][j]) {
				Graph[i][j] = INF;
			}
		}
	}
	scanf("%d %d" ,&v1, &v2);
	dij(1);
	long long R1 = d[v1];
	long long R2 = d[v2];
	memset(dis, false, sizeof(dis));
	dij(v1);
	R1 += d[v2];
	R2 += d[v2];
	memset(dis, false, sizeof(dis));
	dij(v2);
	R1 += d[N];
	memset(dis, false, sizeof(dis));
	dij(v1);
	R2 += d[N];
	if (R1 >= INF && R2 >= INF) {
		printf("-1");
		return 0;
	}
	if (R1 < R2) {
		printf("%lld", R1);
	}
	else printf("%lld", R2);
	return 0;
}