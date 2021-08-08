#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
int  N, r, c,ans=0;
int find(int x, int y, int N) {
    if (r == x && c == y) {
        printf("%d\n", ans);
        return;
    }
    if (r<x+N && c<y+N && r>=x && c>=y) {
        find(x, y, N/2);
        find(x, y+N/2, N/2);
        find(x+N/2, y, N / 2);
        find(x + N / 2, y + N / 2, N / 2);
    }
    else {
        ans += N*N;
    }
}
int main(void) {
    int M=1,x=0,y=0;
    scanf("%d %d %d", &N, &r, &c);
    while (N--) {
        M = M * 2;
    }
    find(0,0, M);
    return 0;
}