#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
char a[26][26];
int visit[26][26];
int cnt;
int dfs(int x,int y) {
	visit[x][y] = 1;
	cnt++;
	if (a[x+1][y] == '1' && visit[x+1][y] == 0) {
		dfs(x + 1, y);
	}
	if (a[x-1][y] == '1' && visit[x-1][y] == 0) {
		dfs(x -1, y);
	}
	if (a[x][y+1] == '1' && visit[x][y+1] == 0) {
		dfs(x, y+1);
	}
	if (a[x][y-1] == '1' && visit[x][y-1] == 0) {
		dfs(x, y-1);
	}
}
int main(void) {
	int N,bnt[1000];
	int k = 0;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%s", a[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt = 0;
			if (a[i][j] == '1' && visit[i][j] == 0) {
				dfs(i, j);
				bnt[k++] = cnt;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = i; j < k; j++) {
			if (bnt[i] > bnt[j]) {
				int tmp = bnt[i];
				bnt[i] = bnt[j];
				bnt[j] = tmp;
			}
		}
	}
	printf("%d\n", k);
	for (int i = 0; i < k; i++) {
		printf("%d\n", bnt[i]);
	}
}