#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int INF = 1000;
int V, E, K;
int Graph[20001][20001];
bool v[20001];
int d[20001];
int getSmallIndex() {
	int min = -INF;
	int index = 0;
	for (int i = 0; i < V; i++) {
		if (d[i] > min && !v[i]&&d[i]!=0) {
			min = d[i];
			index = i;
		}
	}
	return index;
}
void dijkstra(int start) {
	for (int i = 0; i < V; i++) {
		d[i] = Graph[start][i];
	}
	v[start] = true;
	for (int i = 0; i < V - 2; i++) {
		int current = getSmallIndex();
		v[current] = true;
		for (int j = 0; j < V; j++) {
			if (!v[j]) {
				if (d[j] == 0) d[j] = -100;
				if (d[current] + Graph[current][j] > d[j]) {
					d[j] = d[current] + Graph[current][j];
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	int x, y, z;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &x, &y, &z);
		Graph[x][y] = -z;
	}

	dijkstra(K);
	for (int i = 0; i < V; i++) {
		if (d[i] == 0&&i!=K) printf("INF\n");
		else
		printf("%d\n", -d[i]);
	}
	return 0;
}
