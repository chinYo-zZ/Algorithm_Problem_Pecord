class Solution {
public:
	string str;
	int strsize;
	int n, m;
	bool dfs(vector<vector<char>>& grid, int i_, int j_, int index) {
		if (i_ < 0 || j_ < 0 || i_ >= n || j_ >= m || grid[i_][j_] != str[index]) {
			return false;
		}
		if (index == strsize - 1) {
			return true;
		}
		grid[i_][j_] = '0';
		bool a = dfs(grid, i_ - 1, j_, index + 1) ||
		dfs(grid, i_, j_ - 1, index + 1) ||
		dfs(grid, i_ + 1, j_, index + 1) ||
		dfs(grid, i_, j_ + 1, index + 1);
		grid[i_][j_] = str[index];
		return a;
	}

	bool wordPuzzle(vector<vector<char>>& grid, string target) {
		str = target;
		strsize = target.size();
		n = grid.size();
		m = grid[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == target.front()) {
					bool bExist = dfs(grid, i, j, 0);
					if (bExist) {
						return true;
					}
				}
			}
		}
		return false;
	}
};
