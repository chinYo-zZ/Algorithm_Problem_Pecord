#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, m, ans = 0x3f3f3f3f;
int mat[505][505];
bool vis[505] = { false };
int xs, ys, xe, ye;
char dir;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

pair<int, int> dfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	int minv = 510, maxv = 0;
	while (!q.empty())
	{
		auto tmp = q.front();
		q.pop();

		if (tmp.first == n) {
			vis[tmp.second] = true;
			if (tmp.second > maxv) {
				maxv = tmp.second;
			}
			if (tmp.second < minv) {
				minv = tmp.second;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int newx = tmp.first + dx[i];
			int newy = tmp.second + dy[i];
			if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && mat[tmp.first][tmp.second] > mat[newx][newy]) {
				q.push({ newx,newy });
			}
		}
	}
	return { minv,maxv };
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}
	vector<pair<int, int>> section;
	for (int i = 1; i <= m; i++) {
		section.push_back(dfs(1, i));
	}
	int nums = 0;
	for (int i = 1; i <= m; i++) {
		if (!vis[i]) {
			nums++;
		}
	}
	if (nums > 0) {
		cout << 0 << endl << nums;
		return 0;
	}
	sort(section.begin(), section.end(), [](pair<int, int>& a, pair<int, int>& b) ->bool {
		return a.first < b.first;
		});
	int left = 1;
	int cnt = 0;
	while (left <= m) {
		int maxr = 0;
		for (auto ele : section)
			if (ele.first <= left) {
				maxr = max(maxr, ele.second);
			}
			else
			{
				break;
			}
		cnt++;
		left = maxr + 1;
	}
	cout << 1 << endl << cnt;
	return 0;
}
