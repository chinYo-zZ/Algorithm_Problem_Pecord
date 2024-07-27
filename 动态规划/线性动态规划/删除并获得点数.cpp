class Solution {
public://没优化，有点笨，不过AC
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(10005, 0);
        for (int i = 0; i < n; i++) {
            sum[nums[i]]++;
        }

        vector<int> dp(10005, 0);
        dp[0] = 0;
        dp[1] = sum[1];
        dp[2] = max(sum[1], sum[2] * 2);

        for (int i = 3; i <= 10000; i++) {
            dp[i] = max(dp[i - 2] + sum[i] * i, dp[i - 1]);
        }
        return dp[10000];
    }
};
