#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sorted[1000000];
void merge(int a[], int m, int middle, int n) {
    int i = m, j = middle + 1, k = m;
    while (i <= middle && j <= n) {
        if (a[i] < a[j]) {
            sorted[k++] = a[i++];
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
void mergeSort(int a[], int m, int n) {
    if (m < n) {
        int middle = (m + n) / 2;
        mergeSort(a, m, middle);
        mergeSort(a, middle + 1, n);
        merge(a, m, middle, n);
    }
}
int main(void)
{
    int N,a[1000000];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}