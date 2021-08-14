#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
typedef struct queue {
	long long num, i;
}queue;
long long size1 = 0, size2 = 0;
bool visited[10000001];
queue heap_max[10000001], heap_min[10000001];
void insert_max(long long x,long long y) {
	long long idx = ++size1;
	while (x > heap_max[idx / 2].num && idx != 1) {
		heap_max[idx].num = heap_max[idx / 2].num;
		idx = idx / 2;
	}
	heap_max[idx].num = x;
	heap_max[idx].i = y;
}
void deleteheap_max() {
	if (size1 == 0) {
		return 0;
	}
	queue tmp = heap_max[1];
	heap_max[1] = heap_max[size1--];
	long long root = 1;
	long long c = 2;
	while (c <= size1) {
		c = root * 2;
		if (heap_max[c].num < heap_max[c + 1].num && c <= size1 - 1) {
			c++;
		}
		if (heap_max[c].num > heap_max[root].num && c <= size1) {
			queue cmp = heap_max[c];
			heap_max[c] = heap_max[root];
			heap_max[root] = cmp;
		}
		root = c;
	}
}
void insert_min(long long x, long long y) {
	long long idx = ++size2;
	while (x < heap_min[idx / 2].num && idx != 1) {
		heap_min[idx].num = heap_min[idx / 2].num;
		idx = idx / 2;
	}
	heap_min[idx].num = x;
	heap_min[idx].i = y;
}
void deleteheap_min() {
	if (size2 == 0) {
		return 0;
	}
	queue tmp = heap_min[1];
	heap_min[1] = heap_min[size2--];
	long long root = 1;
	long long c = 2;
	while (c <= size2) {
		c = root * 2;
		if (heap_min[c].num > heap_min[c + 1].num && c <= size2 - 1) {
			c++;
		}
		if (heap_min[c].num < heap_min[root].num && c <= size2) {
			queue cmp = heap_min[c];
			heap_min[c] = heap_min[root];
			heap_min[root] = cmp;
		}
		root = c;
	}
}
int main(void) {
	long long T, k, x, y = 0;
	char a;
	scanf("%lld", &T);
	size1 = 0;
	size2 = 0;
	for (long long i = 0; i < T; i++) {
		scanf("%lld", &k);
		y = 0;
		for (long long j = 0; j < k; j++) {
			getchar();
			scanf("%c", &a);
			if (a == 'I') {
				scanf("%lld", &x);
				insert_max(x,j);
				insert_min(x,j);
				visited[j] = true;
			}
			else if (a == 'D') {
				scanf("%lld", &x);
				if (x == 1) {
					while (size1 > 0 && visited[heap_max[1].i] == 0) {
						deleteheap_max();
					}
					if (size1 > 0) {
						visited[heap_max[1].i] = false;
						deleteheap_max();
					}
				}
				else if (x == -1) {
					while (size2 > 0 && visited[heap_min[1].i] == 0) {
						deleteheap_min();
					}
					if (size2 > 0) {
						visited[heap_max[1].i] = false;
						deleteheap_min();
					}
				}
			}
		}
		while (size1>0 && visited[heap_max[1].i]==0)
			deleteheap_max();
		while (size2 > 0 && visited[heap_min[1].i] == 0)
			deleteheap_min();
		if (size1 == 0 && size2 == 0)
			printf("EMPTY\n");
		else
			printf("%lld %lld", heap_max[1].num, heap_min[1].num);
	}

	return 0;
}