#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int k = 0;
typedef struct NODE {
	struct NODE* prev;
	struct NODE* next;
	char data;
}NODE ;
void getNODE(NODE** p) {
	(*p) = (NODE*)malloc(sizeof(NODE));
}
void add(NODE *ma,char dapr,char dane) {
	NODE* p;
	NODE* q;
	getNODE(&p);
	getNODE(&q);
	p->next = NULL;
	p->prev = NULL;
	q->prev = NULL;
	q->next = NULL;
	p->data = dapr;
	q->data = dane;
	if (dapr != '.') {
		ma->prev = p;
	}
	if (dane != '.') {
		ma->next = q;
	}
}
void find(NODE* p,char a,char b,char c) {
	if (p != NULL&&k==0) {
		if (p->data == a) {
			add(p, b, c);
			k = 1;
			return;
		}
		find(p->prev, a, b, c);
		find(p->next, a, b, c);
	}
}
void preorderTraversal(NODE* p) {
	if (p != NULL) {
		printf("%c", p->data);
		preorderTraversal(p->prev);
		preorderTraversal(p->next);
	}
}
void inorderTraversal(NODE* p) {
	if (p != NULL) {
		inorderTraversal(p->prev);
		printf("%c", p->data);
		inorderTraversal(p->next);
	}
}
void postorderTraversal(NODE* p) {
	if (p != NULL) {
		postorderTraversal(p->prev);
		postorderTraversal(p->next);
		printf("%c", p->data);
	}
}
int main()
{
	NODE* p;
	getNODE(&p);
	p->next = NULL;
	p->prev = NULL;
	p->data = NULL;
	int N;
	char a, b, c;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		getchar();
		k = 0;
		scanf("%c %c %c", &a, &b, &c);
		if (i == 0) {
			p->data = a;
		}
		find(p, a, b, c);
	}
	preorderTraversal(p);
	printf("\n");
	inorderTraversal(p);
	printf("\n");
	postorderTraversal(p);
	printf("\n");
	return 0;
}
