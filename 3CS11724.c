#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
int Graph[1001][1001];
int visit[1001];
int dfs(int x,int N) {
    for (int i = 1; i <= N; i++) {
        if (visit[i] == 0 && Graph[x][i] == 1) {
            visit[i] = 1;
            dfs(i, N);
        }
    }
}
int main(void) {
    int N, M,x,y,cnt=0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        Graph[x][y] = 1;
        Graph[y][x] = 1;
    }
    for (int i = 1; i <= N; i++) {
        if (visit[i] == 0) {
            cnt++;
            visit[i] = 1;
            dfs(i,N);
        }
    }
    printf("%d", cnt);
    return 0;

}