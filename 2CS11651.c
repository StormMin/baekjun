#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct coordinate {
    int x;
    int y;
}cdt;
cdt sorted[100000];
void merge(cdt a[], int m, int middle, int n) {
    int i = m, j = middle + 1, k = m;
    while (i <= middle && j <= n) {
        if (a[i].y < a[j].y) {
            sorted[k++] = a[i++];
        }
        else if (a[i].y == a[j].y) {
            if (a[i].x < a[j].x) {
                sorted[k++] = a[i++];
            }
            else {
                sorted[k++] = a[j++];
            }
        }
        else {
            sorted[k++] = a[j++];
        }
    }
    if (i > middle) {
        for (int t = j; t <= n; t++) {
            sorted[k++] = a[t];
        }
    }
    else {
        for (int t = i; t <= middle; t++) {
            sorted[k++] = a[t];
        }
    }
    for (int t = m; t <= n; t++) {
        a[t] = sorted[t];
    }
}
void mergeSort(cdt a[], int m, int n) {
    if (m < n) {
        int middle = (m + n) / 2;
        mergeSort(a, m, middle);
        mergeSort(a, middle + 1, n);
        merge(a, m, middle, n);
    }
}
int main(void)
{
    int N,M;
    cdt a[100000];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a[i].x,&a[i].y);
    }
    mergeSort(a, 0, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", a[i].x, a[i].y);
    }
   
    return 0;
}