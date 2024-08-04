#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, m, t;
int dp[105][205][205];
int cost[105];
int tim[105];
int main() {
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i] >> tim[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= t; k++) {
				if (j >= cost[i] && k >= tim[i]) {
					dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - cost[i]][k - tim[i]] + 1);
				}
				else
				{
					dp[i][j][k] = dp[i - 1][j][k];
				}
			}
		}
	}
	cout << dp[n][m][t];
	return 0;
}
