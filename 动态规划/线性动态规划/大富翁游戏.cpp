//网易2021校招笔试-国际化游戏拓展专员-技术（企业发展部）
//https://www.nowcoder.com/questionTerminal/15771d999d1047eb86eca1e63d05b06a?examPageSource=%E5%85%AC%E5%8F%B8%E7%9C%9F%E9%A2%98%E7%AD%94%E6%A1%88&toCommentId=19929400#jsEditorModuleBody
#include <iostream>

using namespace std;
const int N = 1000;
int m, ans = 0;
int coin[N];
int dp[N];

int main() {
	int a, k = 1;
	cin >> m;
	while (cin >> a) { // 注意 while 处理多个 case
		coin[k] = a;
		k++;
		if ('\n' == cin.get())
		{
			break;
		}
	}
	dp[0] = m;
	int i = 1;
	if (m >= 2) {
		m = m - 2;
		dp[i] = m + coin[i];
		ans = dp[i];
		i++;
	}
	else {
		cout << m;
		return 0;
	}
	for (; i < k; i++) {
		if (dp[i - 2] >= 3) {
			if (dp[i - 1] >= 2) {
				dp[i] = max(dp[i - 1] - 2 + coin[i], dp[i - 2] - 3 + coin[i]);
				if (dp[i] > ans) {
					ans = dp[i];
				}
			}
			else
			{
				dp[i] = dp[i - 2] - 3 + coin[i];
				if (dp[i] > ans) {
					ans = dp[i];
				}
			}
		}
		else
		{
			if (dp[i - 1] >= 2) {
				dp[i] = dp[i - 1] - 2 + coin[i];
				if (dp[i] > ans) {
					ans = dp[i];
				}
			}
			else
			{
				cout<<ans;
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}
// 64 位输出请用 printf("%lld")
