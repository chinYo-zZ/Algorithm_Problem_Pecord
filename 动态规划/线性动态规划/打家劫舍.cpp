class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        if(n == 1){
            return dp[1];
        }
        dp[2] = max(nums[0], nums[1]);
        if(n == 2){
            return dp[2];
        }
        for (int i = 3; i <= n; i++) {
            //偷窃第 k 间房屋，那么就不能偷窃第 k−1 间房屋，偷窃总金额为前 k−2 间房屋的最高总金额与第 k 间房屋的金额之和。不偷窃第 k 间房屋，偷窃总金额为前 k−1 间房屋的最高总金额。
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[n];
    }
};
