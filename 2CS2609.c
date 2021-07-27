#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N, M, mix = 0, max = 0, temp = 0;
    scanf("%d %d", &N, &M);
    if (N > M) {
        temp = N;
        N = M;
        M = temp;
    }
        for (int i = 1; i <= N; i++) {
            if ((N % i == 0) && (M % i == 0)) {
                mix = i;
            }
        }
        printf("%d\n", mix);
        for (int j = M; j <= N * M; j++) {
            if ((j % N == 0) && (j % M == 0)) {
                max = j;
                break;
            }
        }
        printf("%d\n", max);
    return 0;
}