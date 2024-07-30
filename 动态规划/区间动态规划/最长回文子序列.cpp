class Solution {
public:
    int dp[1005][1005] = {0};
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            dp[i][i] = 1;
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 2;
            }
        };

        dp[n - 1][n - 1] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0, j = len - 1; j <= n - 1; i++, j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
