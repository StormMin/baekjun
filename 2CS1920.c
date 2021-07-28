#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int binary_find(int a[], int n, int key) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) {
            return 1;
        }
        else if (a[mid] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return 0;
}
void quick_sort(int a[], int start, int end) {
    if (start >= end) {
        return;
    }
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;
    while (i <= j) {
        while (a[i] <= a[key]) {
            i++;
        }
        while (a[j] >= a[key]&&j>start) {
            j--;
        }
        if (i > j) {
            temp = a[j];
           a[j] = a[key];
            a[key] = temp;
        }
        else {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    quick_sort(a, start, j - 1);
    quick_sort(a, j + 1, end);
}
int main(void)
{
    int N, M,b, cnt = 0;
    int a[10000];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    quick_sort(a, 0, N-1);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &b);
        int cnt = binary_find(a, N, b);
        if (cnt == 1) printf("1\n");
        else printf("0\n");
    }
    return 0;
}