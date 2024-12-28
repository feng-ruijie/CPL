#include <stdio.h>
#include <stdlib.h>

int mp[3103][3103];

int *acc(int x, int y) {
	return &mp[1050 + x][1050 + y];
}


#define safe(i, j) ((0 <= (i) && (i) <= 3102 && 0 <= (j) && (j) <= 3102) ? mp[i][j] : 0)
void pref() {
	for (int i = 0; i <= 3102; i++) {
		for (int j = 0; j <= 3102; j++) {
			mp[i][j] += safe(i - 1, j + 1) + safe(i - 1, j - 1) - safe(i - 2, j);
		}
	}
}

int main() {
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= q; i++) {
		int x, y, d;
		scanf("%d %d %d", &x, &y, &d);
		(*acc(x - d, y))++;
		(*acc(x + 1, y - (d + 1)))--;
		(*acc(x + 1, y + (d + 1)))--;
		(*acc(x + (d + 2), y))++;

		(*acc(x - (d - 1), y))++;
		(*acc(x + 1, y - d))--;
		(*acc(x + 1, y + d))--;
		(*acc(x + (d + 1), y))++;
	}
	pref();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d%c", *acc(i, j), " \n"[j == m]);
		}
	}
}