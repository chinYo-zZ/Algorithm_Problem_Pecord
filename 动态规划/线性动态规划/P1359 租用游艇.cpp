#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
//租船成本
int cost[205][205] = { 0 };
int n;
// 租船点i到n所需最小费用
int dp[205];
int main()
{
	cin >> n;
	//初始化成本矩阵（邻接矩阵）
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cin >> cost[i][j];
		}
		//费用拉到最高，为min服务
		dp[i] = 1e6;
	}
	//自己到自己费用0
	dp[n] = 0;
	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 1; j <= n; j++) {
			//自己直达或者找一个下家，在下家那直达，选费用小的
			dp[i] = min(dp[i], dp[j] + cost[i][j]);
		}
	}
	cout << dp[1] << endl;
	return 0;
}
