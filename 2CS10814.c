#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nameplate {
    int age;
    char name[101];
    int order;

}na;
na sorted[100000];
void merge(na a[], int m, int middle, int n) {
    int i = m, j = middle + 1, k = m;
    while (i <= middle && j <= n) {
        if (a[i].age < a[j].age) {
            sorted[k++] = a[i++];
        }
        else if (a[i].age == a[j].age) {
            if (a[i].order < a[j].order) {
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
void mergeSort(na a[], int m, int n) {
    if (m < n) {
        int middle = (m + n) / 2;
        mergeSort(a, m, middle);
        mergeSort(a, middle + 1, n);
        merge(a, m, middle, n);
    }
}
int main(void)
{
    int N,tmp=1;
    na a[100000],b;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %s", &a[i].age, a[i].name);
        a[i].order = i;
    }
    mergeSort(a, 0, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%d %s\n", a[i].age, a[i].name);
    }
    return 0;
}