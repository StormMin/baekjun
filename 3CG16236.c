#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int a[21][21];
typedef struct {
	int x,y;
	int time;
}queue;
bool visited[21][21];
queue s[10000];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int front = -1, rear = -1,front2=-1,rear2=-1;
queue p[10000];
queue heap[50]; 
int SIZE = 0;
bool operater(queue p1, queue p2) {
	if (p1.time > p2.time)
		return true; 
	else if (p1.time == p2.time && p1.y > p2.y) 
		return true; 
	else if (p1.time == p2.time && p1.y == p2.y && p1.x > p2.x) 
		return true; 
	return false;

}
void insert(queue T) {
	int idx = ++SIZE;
	while (idx != 1 && operater(heap[idx/2],T)==1) {
		heap[idx] = heap[idx / 2];
		idx /= 2;
	}
	heap[idx] = T;
}
int main(void) {
	int N,size=2,cnt=0;
	int duration = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 9) {
				s[++rear].x = j;
				s[rear].y = i;
				s[rear].time = 0;
				a[i][j] = 0;
			}
		}
	}
	while (front != rear) {
		++front;
		front2 = -1, rear2 = -1;
		p[++rear2].x = s[front].x;
		p[rear2].y = s[front].y;
		p[rear2].time = s[front].time;
		for (int i = 0; i < N; i++) {
			memset(visited[i], false, sizeof(visited[i]));
		}
		while (front2 != rear2) {
			++front2;
			for (int i = 0; i < 4; i++) {
				int nx = p[front2].x + dx[i];
				int ny = p[front2].y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < N && ny < N && visited[ny][nx] == 0 && size >= a[ny][nx]) {
					p[++rear2].x = nx;
					p[rear2].y = ny;
					p[rear2].time = p[front2].time + 1;
					visited[ny][nx] = 1;
					if (size > a[ny][nx] && a[ny][nx] > 0) {
						insert(p[rear2]);
					}
				}
			}
		}
		if (SIZE > 0) {
			s[++rear].x = heap[1].x;
			s[rear].y = heap[1].y;
			s[rear].time = heap[1].time;
			a[heap[1].y][heap[1].x] = 0;
			cnt++;
			if (size == cnt) {
				size++;
				cnt = 0;
			}
			SIZE = 0;
		}
	}
	printf("%d", s[rear].time);

	return 0;
}