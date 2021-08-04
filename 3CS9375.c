#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct cloth {
	char wear[21], name[21];
}cl;
int heaps(int number, cl a[]) {
    for (int i = 1; i < number; i++) {
        int c = i;
        do {
            int root = (c - 1) / 2;
            if (strcmp(a[root].name,a[c].name)<0) {
                cl temp = a[root];
                a[root] = a[c];
                a[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
    for (int i = number - 1; i >= 0; i--) {
        cl temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        int root = 0;
        int c = 1;
        do {
            c = 2 * root + 1;
            if (c < i - 1 && strcmp(a[c].name,a[c+1].name)<0) {
                c++;
            }
            if (strcmp(a[root].name,a[c].name)<0 && c < i) {
                cl temp = a[root];
                a[root] = a[c];
                a[c] = temp;
            }
            root = c;
        } while (c < i);
    }
}
int main(void) {
	int N,M;
    long long so[31];
	cl a[31],b;
	scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &M);
        getchar();
        for (int j = 0; j < M; j++) {
            scanf("%s %s", a[j].wear, a[j].name);
        }
        heaps(M, a);
         int cnt = 1,k=0;
        for (int j = 0; j < M-1; j++) {
            if (strcmp(a[j].name,a[j+1].name)==0) {
                cnt++;
            }
            else {
                so[k++] = cnt;
                cnt = 1;

            }
        }
        so[k] = cnt;
        long long sum = 1;
        for (int j = 0; j <= k; j++) {
            sum *= (so[j] + 1);
        }
        printf("%lld\n", (sum - 1));

	}
	return 0;
}