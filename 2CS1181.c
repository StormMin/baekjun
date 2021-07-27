#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    unsigned int N,cnt=0,k=0,bnt=0;
    scanf("%d", &N);
    for (int i = 0; i < 9999999; i++) {
        k = i;
        cnt = 0;
        while (k != 0) {
            if (k % 10 == 6) {
                cnt++;
                if (cnt == 3) {
                    bnt++;
                    break;
                }
            }
            else cnt = 0;
            k /= 10;
        }
        if (bnt == N) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}