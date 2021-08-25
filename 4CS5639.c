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
	int data;
}NODE ;
void getNODE(NODE** p) {
	(*p) = (NODE*)malloc(sizeof(NODE));
}
void find(NODE* p, int data) {
	if (p != NULL&&k==0) {
		if (p->data > data) {
			find(p->prev, data);
			if (k == 0) {
				NODE* q;
				getNODE(&q);
				q->data = data;
				q->prev = NULL;
				q->next = NULL;
				p->prev = q;
				k = 1;
			}
		}
		else if (p->data < data) {
			find(p->next, data);
			if (k == 0) {
				NODE* q;
				getNODE(&q);
				q->data = data;
				q->prev = NULL;
				q->next = NULL;
				p->next = q;
				k = 1;
			}
		}
	}
}

void postorderTraversal(NODE* p) {
	if (p != NULL) {
		postorderTraversal(p->prev);
		postorderTraversal(p->next);
		printf("%d\n", p->data);
	}
}
int main()
{
	NODE* p;
	getNODE(&p);
	p->next = NULL;
	p->prev = NULL;
	p->data = NULL;
	int a,i=0;
	while(scanf("%d",&a)!=EOF) {
		k = 0;
		if (i == 0) {
			p->data = a;
			i = 1;
		}
		else
		find(p, a);
	}
	postorderTraversal(p);
	printf("\n");
	return 0;
}
