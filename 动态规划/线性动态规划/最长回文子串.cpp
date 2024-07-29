class Solution {
public:
	bool dp[1005][1005] = { false };
	int maxlen = 1;
	int lefr_ = 0, right_ = 0;
	string longestPalindrome(string s) {
		int n = s.size();

		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
		}
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1]) {
				dp[i][i + 1] = true;
				lefr_ = i;
				right_ = i + 1;
				maxlen = 2;
			}
		}

		for (int len = 3; len <= n; len++) {
			for (int i = 0, j = len - 1; j < n; i++, j++) {
				if (dp[i][j] == false) {
					if (i + 1 <= j - 1) {
						dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
						if (dp[i][j] && j - i + 1 > maxlen) {
							lefr_ = i;
							right_ = j;
							maxlen = j - i + 1;
						}
					}
				}
			}
		}

		return s.substr(lefr_, maxlen);
	}
};
