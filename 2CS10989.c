#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cnt[10001];
int main(void)
{
    int N,M;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &M);
        cnt[M]++;
    }
    for (int i = 0; i < 10001; i++) {
        if (cnt[i] == 0) continue;
        else {
            for (int j = 0; j < cnt[i]; j++) {
                printf("%d\n", i);
            }
        }
    }
   
    return 0;
}