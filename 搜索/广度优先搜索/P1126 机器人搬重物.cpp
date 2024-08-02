#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, m,ans = 0x3f3f3f3f;
int mat[55][55];
int vis[55][55];
int xs, ys, xe, ye;
char dir;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

struct State
{
	int x, y;
	int timecost;
	int dir; // 0:s  1:w  2:n  3:e
};

int GetleftDir(int cur) {
	int tmp = cur - 1;
	if (tmp < 0) {
		return 3;
	}
	return tmp;
}

int GetRightDir(int cur) {
	int tmp = cur + 1;
	if (tmp > 3) {
		return 0;
	}
	return tmp;
}

int GetBackDir(int cur) {
	int tmp = (cur + 2) % 4;
	return tmp;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
			vis[i][j] = 0x3f3f3f3f;
		}
	}
	cin >> xs >> ys >> xe >> ye >> dir;
	
	int dir_ = 0;
	switch (dir)
	{
	case 'S':
		dir_ = 0; break;
	case 'W':
		dir_ = 1; break;
	case 'N':
		dir_ = 2; break;
	case 'E':
		dir_ = 3; break;
	}

	queue<State> q;
	vis[xs][ys] = 0;
	q.push({ xs,ys,0,dir_ });
	while (!q.empty())
	{
		auto tmp = q.front();
		q.pop();
		if (tmp.x == xe && tmp.y == ye) {
			ans = min(ans,tmp.timecost);
			continue;
		}
		if (tmp.timecost >= ans) {
			continue;
		}

		{
			bool bIsBlock = false;
			for (int comindex = 1; comindex <= 3; comindex++) {
				int xx = tmp.x + comindex * dx[tmp.dir];
				int yy = tmp.y + comindex * dy[tmp.dir];
				if (!bIsBlock&& xx >= 1 && xx <= n - 1 && yy >= 1 && yy <= m - 1 &&
					mat[xx][yy] == 0 && mat[xx + 1][yy] == 0 && mat[xx][yy + 1] == 0 && mat[xx + 1][yy + 1] == 0) {
					if (vis[xx][yy] > tmp.timecost + 1) {
						vis[xx][yy] = tmp.timecost + 1;
						q.push({ xx,yy,tmp.timecost + 1,tmp.dir });
					}
				}
				else
				{
					bIsBlock = true;
				}
			}
		}
		{
			bool bIsBlock = false;
			int postdir = GetRightDir(tmp.dir);
			for (int comindex = 1; comindex <= 3; comindex++) {
				int xx = tmp.x + comindex * dx[postdir];
				int yy = tmp.y + comindex * dy[postdir];
				if (!bIsBlock && xx >= 1 && xx <= n - 1 && yy >= 1 && yy <= m - 1 &&
					mat[xx][yy] == 0 && mat[xx + 1][yy] == 0 && mat[xx][yy + 1] == 0 && mat[xx + 1][yy + 1] == 0) {
					if (vis[xx][yy] > tmp.timecost + 2) {
						vis[xx][yy] = tmp.timecost + 2;
						q.push({ xx,yy,tmp.timecost + 2,postdir });
					}
				}
				else
				{
					bIsBlock = true;
				}
			}
		}
		{
			bool bIsBlock = false;
			int postdir = GetBackDir(tmp.dir);
			for (int comindex = 1; comindex <= 3; comindex++) {
				int xx = tmp.x + comindex * dx[postdir];
				int yy = tmp.y + comindex * dy[postdir];
				if (!bIsBlock && xx >= 1 && xx <= n - 1 && yy >= 1 && yy <= m - 1 &&
					mat[xx][yy] == 0 && mat[xx + 1][yy] == 0 && mat[xx][yy + 1] == 0 && mat[xx + 1][yy + 1] == 0) {
					if (vis[xx][yy] > tmp.timecost + 3) {
						vis[xx][yy] = tmp.timecost + 3;
						q.push({ xx,yy,tmp.timecost + 3,postdir });
					}
				}
				else
				{
					bIsBlock = true;
				}
			}
		}
		{
			bool bIsBlock = false;
			int postdir = GetleftDir(tmp.dir);
			for (int comindex = 1; comindex <= 3; comindex++) {
				int xx = tmp.x + comindex * dx[postdir];
				int yy = tmp.y + comindex * dy[postdir];
				if (!bIsBlock && xx >= 1 && xx <= n - 1 && yy >= 1 && yy <= m - 1 &&
					mat[xx][yy] == 0 && mat[xx + 1][yy] == 0 && mat[xx][yy + 1] == 0 && mat[xx + 1][yy + 1] == 0) {
					if (vis[xx][yy] > tmp.timecost + 2) {
						vis[xx][yy] = tmp.timecost + 2;
						q.push({ xx,yy,tmp.timecost + 2,postdir });
					}
				}
				else
				{
					bIsBlock = true;
				}
			}
		}
	}

	if (ans == 0x3f3f3f3f) {
		cout<<-1;
	}
	else
	{
		cout<<ans;
	}

	return 0;
}
