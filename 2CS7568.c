#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct dunch {
    int we;
    int he;
    int rank;
}dunch;
int main(void)
{
    int N,tmp=1;
    dunch a[50];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a[i].we, &a[i].he);
    }
    for (int i = 0; i < N; i++) {
        tmp = 1;
        for (int j = 0; j < N; j++) {
            if ((a[i].he < a[j].he) && (a[i].we < a[j].we)) {
                tmp++;
            }
        }
        a[i].rank = tmp;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i].rank);
    }
    return 0;
}