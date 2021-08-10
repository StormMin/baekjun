#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int heap[100001];
int size=0;
void insert(int data) {
	int idx = ++size;
	while (idx!=1&&data < heap[idx / 2]) {
		heap[idx] = heap[idx / 2];
		idx /= 2;
	}
	heap[idx] = data;
}
void deleteheap() {
	int tmp = heap[1];
	heap[1] = heap[size];
	heap[size--] = tmp;
	int root = 1;
	int c = 0,cmt;
	do {
		c = root * 2;
		if (heap[c] > heap[c + 1] && c <= size - 1) {
			c++;
		}
		if (heap[c] < heap[root] && c <= size) {
			cmt = heap[c];
			heap[c] = heap[root];
			heap[root] = cmt;
		}
		root = c;
	} while (c<=size);
	printf("%d\n", tmp);
}
int main(void) {
	int N,M;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &M);
		if (M == 0) {
			if (size == 0) {
				printf("0");
			}
			else
			deleteheap();
		}
		else insert(M);
	}
}