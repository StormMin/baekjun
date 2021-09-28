#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int tmp;
char str[1000000];
bool visited[1000000];
char bomb[38];
int check(int i, int k) {
	if (strlen(str) <= i) return 0;
	if (k == strlen(bomb)) {
		return 1;
	}
	while (visited[i] != 0) {
		i++;
	}
	visited[i] = 1;
	if (str[i] == bomb[k]) {
		tmp = check(i + 1, k + 1);
	}
	if (tmp != 1) {
		visited[i] = 0;
	}
}
int main() {
	scanf("%s", str);
	scanf("%s", bomb);
	for (int i = 0; i < strlen(str); i++) {
		tmp = 0;
		if (str[i] == bomb[0] && visited[i] == 0) {
			check(i, 0);
			if (tmp == 1) {
				i = i - strlen(bomb);
				if (i < 0) i = 0;
			}
		}
	}
	int k = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (visited[i] == 0) {
			printf("%c", str[i]);
			k = 1;
		}
	}
	if (k == 0) printf("FRULA");

	return 0;
}