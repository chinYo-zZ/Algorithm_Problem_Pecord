#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
using namespace std;
int r, c;
int mat[105][105];
int dp[105][105];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int dfs(int x, int y) {
	if (dp[x][y]) {
		return dp[x][y];
	}
	int ans = 0;
	for (int i = 0; i <= 3; i++) {
		int newx = x + dx[i];
		int newy = y + dy[i];
		if (newx >= 0 && newx < r && newy >= 0 && newy<c && mat[x][y]>mat[newx][newy]) {
			ans = max(ans,dfs(newx, newy) + 1);
		}
	}
	return dp[x][y] = ans;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> mat[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			ans = max(ans, dfs(i,j)+1);
		}
	}
	cout << ans;
	return 0;
}
