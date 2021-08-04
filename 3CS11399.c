#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int a[1001],b[1001];
int heaps(int heap[], int number) {
    for (int i = 1; i < number; i++) {
        int c = i;
        do {
            int root = (c - 1) / 2;
            if (heap[root] < heap[c]) {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
    for (int i = number - 1; i >= 0; i--) {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int c = 1;
        do {
            c = 2 * root + 1;
            if (c < i - 1 && heap[c] < heap[c + 1]) {
                c++;
            }
            if (heap[root] < heap[c] && c < i) {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < i);
    }
}
int main(void) {
	int N,M,sum=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
    heaps(a, N);
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            b[i] = a[i];
        }
        else
        b[i] = a[i] + b[i - 1];
        sum += b[i];
    }
    printf("%d", sum);
	return 0;
}