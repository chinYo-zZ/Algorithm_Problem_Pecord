#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, m, num;
int dp[1005];
int weight[1005];
int va[1005];
int group[105];
int g[205][205]; //g[i][j]表示存储小组i中的第j个物品的编号
int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		int in;
		cin >> weight[i] >> va[i] >> in;
		num = max(num, in);
		group[in]++;
		g[in][group[in]] = i;
	}

	for (int i = 1; i <= num; i++) { // 小组
		for (int j = m; j >= 0; j--) {
			for (int k = 1; k <= group[i]; k++) { // k组中有几个物品
				if (j >= weight[g[i][k]]) {
					dp[j] = max(dp[j], dp[j - weight[g[i][k]]] + va[g[i][k]]);
				}
			}
		}
	}
	cout << dp[m];

	int&& mo = 8;
	return 0;
}
