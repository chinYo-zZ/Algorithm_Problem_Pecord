#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_Value = 0x3f3f3f3f;

int n;
int dp[4][1000005];
int coins[4] = { 0, 1, 5, 11 };
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		dp[0][i] = MAX_Value;
	}

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j >= coins[i])
			{
				dp[i][j] = min(dp[i][j - coins[i]] + 1, dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[3][n];
	return 0;
}
