class Solution {
public:
	bool dp[305] = { false };
	bool wordBreak(string s, vector<string>& wordDict) {
		int n = s.size();
		for (int i = 0; i < n; i++) {
			for (int j = i; j >= 0; j--) {
				//如果搜到了直接下一轮循环
				if (!dp[i]) {
					bool CheckWord = false;
					for (auto& word : wordDict) {
						if (s.substr(j, i - j + 1) == word) {
							CheckWord = true;
							break;
						}
					}
					if (j - 1 < 0) {
						//一般是第一个单词会触发
						dp[i] = CheckWord;
					}
					else {
						dp[i] = dp[j - 1] && CheckWord;
					}
				}
				else {
					break;
				}
			}
		}

		return dp[n - 1];
	}
};
