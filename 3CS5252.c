#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>


int main(void) {
	int N, M,k,t=0,cnt=0;
	char* a,*tmp;
	scanf("%d", &N);
	scanf("%d", &M);
	getchar();
	a = (char*)malloc(sizeof(char) * (M));
	scanf("%s", a);
	for (int i = 0; i < M; i++) {
		if (a[i] == 'O') continue;
		k = i;
		t = 0;
		while (a[i + 1] == 'O' && a[i + 2] == 'I') {
			t++;
			i += 2;
			if (t == N) {
				cnt++;
				t--;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}