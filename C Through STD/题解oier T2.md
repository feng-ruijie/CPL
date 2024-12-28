## T2 轰炸 题解
这个题是纯纯的打地鼠改编。不过打地鼠的三种思路只有第三种能够在时限内通过。
将打地鼠的二维前缀和替换为二维差分即可，有关二维差分可以参考[这个](https://zhuanlan.zhihu.com/p/439268614)

你可以选择将地图旋转45度，然后进行二维前缀和，这也是我的想法（代码写得比较丑陋就不贴了）。助教给出了一种不用旋转的方法，参考[这个的3.6.5](https://njusecourse.feishu.cn/wiki/U0s1wfHrliYGjSkfm0scGbIMntb)

下面给出助教的代码
```c
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