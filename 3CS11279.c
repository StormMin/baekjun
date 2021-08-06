#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
int heap[1000001];
int size = 0;
void insert(int data) {
    int idx = ++size;
    while (idx != 1 && data > heap[idx / 2]) {
        heap[idx] = heap[idx / 2];
        idx /= 2;
    }
    heap[idx] = data;
}
int deleteheap() {
    if (size == 0) {
        return 0;
    }
    int tmp = heap[1];
    heap[1] = heap[size--];
    int c = 1;
    int root = 1;
    do {
        c = 2 * root;
        if (c <= size-1 && heap[c] < heap[c + 1]) {
            c++;
        }
        if (heap[c] > heap[root] && c <= size) {
            int cnt = heap[c];
            heap[c] = heap[root];
            heap[root] = cnt;
        }
        root = c;
    } while (c <= size);
    return tmp;
}
int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x == 0)
        {
            printf("%d\n", deleteheap());
        }
        else
        {
            insert(x);
        }
    }
    return 0;

}