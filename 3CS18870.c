#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
int a[1000001];
int sorted[1000001];
int heap[1000001];
int size = 0;
void insert(int data) {
    int idx=++size;
    while (idx!=1&&data < heap[idx/2]) {
        heap[idx] = heap[idx / 2];
        idx /= 2;
    }
    heap[idx] = data;
}
int deleteheap(int x) {
    int tmp;
    tmp = heap[1];
    heap[1] = heap[size];
    heap[size--] = tmp;
    int c = 1;
    int root = 1;
    do {
        c = root * 2;
        if (c <= size - 1 && heap[c] > heap[c + 1]) {
            c++;
        }
        if (c <= size && heap[c] < heap[root]) {
            int cmp = heap[c];
            heap[c] = heap[root];
            heap[root] = cmp;
        }
        root=c;
    } while (c <= size);
    return tmp;
}
int binaryfd(int a[],int N, int key) {
    int low = 1,mid,high=N-1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) {
            printf("%d ", mid-1);
            return;
        }
        else if (a[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
}
int main(void) {
    int N,cnt=0,k=1;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            sorted[k++] = deleteheap(1);
        }
        else {
            cnt = deleteheap(1);
            if (cnt == heap[size+2]) {
                continue;
            }
            sorted[k++] = cnt;
        }
    }
    for (int i = 1; i <= N; i++) {
        binaryfd(sorted, k, a[i]);
    }
    return 0;

}