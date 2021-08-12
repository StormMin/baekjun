#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
long long heap[1000001];
int size = 0;
int insert(long long x) {
	int idx=++size;
	while (abs(x) <= abs(heap[idx / 2]) && idx != 1) {
		if (abs(x) == abs(heap[idx / 2])) {
			if (x < heap[idx / 2]) {
				heap[idx] = heap[idx / 2];
				idx = idx / 2;
			}
			else break;
		}
		else {
			heap[idx] = heap[idx / 2];
			idx = idx / 2;
		}
	}
	heap[idx] = x;
}
int deleteheap() {
	long long tmp = heap[1];
	heap[1] = heap[size];
	heap[size--] = tmp;
	int root = 1;
	int c;
	do{
		c = root * 2;
		if (abs(heap[c]) > abs(heap[c + 1]) && c <= size - 1) {
			c++;
		}
		else if (abs(heap[c]) == abs(heap[c + 1]) && c <= size - 1) {
			if (heap[c] > heap[c + 1]) {
				c++;
			}
		}
		if (abs(heap[c]) < abs(heap[root]) && c <= size) {
			int cmp = heap[c];
			heap[c] = heap[root];
			heap[root] = cmp;
		}
		else if (abs(heap[c]) == abs(heap[root]) && c <= size) {
			if (heap[c] < heap[root]) {
				long long cmp = heap[c];
				heap[c] = heap[root];
				heap[root] = cmp;
			}
		}

		root = c;
	} while (c<=size);
	printf("%lld\n", tmp);
}
int main() {
	int N;
	long long M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &M);
		if (M != 0) {
			insert(M);
		}
		else {
			if (size == 0) {
				printf("0\n");
			}
			else {
				deleteheap();
			}
		}
	}
}