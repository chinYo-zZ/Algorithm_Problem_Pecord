#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, m;
int dp[30][30005];
int cost[30];
int va[30];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> cost[i] >> va[i];
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (j >= cost[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i-1][j - cost[i]] + cost[i] * va[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[m][n];
	return 0;
}
