#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <memory>
#include <string.h>
#include <list>
#include <unordered_set>
using namespace std;
const int MAX_Value = 0x3f3f3f3f;

class Solution {
public:
	vector<vector<int>> g;

	int dfs(int x, int fa, vector<int>& inTime) {
		int MinTime = inTime[x];
		int CurTime = 0;
		for (auto y : g[x]) {
			if (y != fa) {
				int TmpTime = dfs(y, x, inTime);
				CurTime = max(CurTime, TmpTime);
			}
		}
		return MinTime + CurTime;
	}

	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		g.resize(n);
		for (int i = 0; i < n; i++) {
			if (manager[i] != -1) {
				g[i].push_back(manager[i]);
				g[manager[i]].push_back(i);
			}
		}

		return dfs(headID,-1,informTime);
	}
};

int main()
{
	return 0;
}
