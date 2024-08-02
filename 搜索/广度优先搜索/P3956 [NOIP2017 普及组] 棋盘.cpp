//有问题的答案，编译还死活不过，洛谷啥玩意编译器
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int m, n, x, y, c, ans = INT_MAX;
int mat[110][110]; // 0 无色 1 红色 2 黄色
int vis[110][110];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

struct nodes
{
	int x, y;
	int color;//变的色  ： -1 没变 1 变红 2 变黄
	int cost;
};

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> c;
		mat[x][y] = c + 1;
	}
	vector<vector<int>> vis(n+1,vector<int>(n+1,INT_MAX));

	queue<nodes> que;
	vis[1][1] = 0;
	que.push({ 1,1,-1,0 });
	while (!que.empty())
	{
		auto tmp = que.front();
		que.pop();

		if (tmp.x == m && tmp.y == m) {
			ans = min(ans, tmp.cost);
		}
		if (tmp.cost >= ans) {
			continue;
		}
		for (int i = 0; i <= 3; i++) {
			int xx = tmp.x + dx[i];
			int yy = tmp.y + dy[i];
			if (xx >= 1 && xx <= m && yy >= 1 && yy <= m) {//在地图范围内
				if (tmp.color == -1) {//原来格子是有颜色的
					if (mat[tmp.x][tmp.y] == mat[xx][yy] && vis[xx][yy] > tmp.cost) { // 颜色相同
						vis[xx][yy] = tmp.cost;
						que.push({ xx,yy,-1,tmp.cost });
					}
					else if (mat[xx][yy] != 0 && mat[tmp.x][tmp.y] != mat[xx][yy] && vis[xx][yy] > tmp.cost + 1) { // 颜色不同
						vis[xx][yy] = tmp.cost + 1;
						que.push({ xx,yy, -1,tmp.cost + 1 });
					}
					else if (mat[xx][yy] == 0 && vis[xx][yy] > tmp.cost + 2) { //下个格子没颜色
						vis[xx][yy] = tmp.cost + 2;
						que.push({ xx,yy,mat[tmp.x][tmp.y],tmp.cost + 2 });
					}
				}
				else {//原来格子没颜色
					if (tmp.color != 0 && tmp.color == mat[xx][yy] && vis[xx][yy] > tmp.cost) {
						vis[xx][yy] = tmp.cost;
						que.push({ xx,yy,-1,tmp.cost });
					}
					else if (tmp.color != 0 &&tmp.color != mat[xx][yy] && vis[xx][yy] > tmp.cost + 1) {
						vis[xx][yy] = tmp.cost+1;
						que.push({ xx,yy,-1,tmp.cost + 1 });
					}
				}
			}
		}
	}

	if (ans == INT_MAX) {
		cout << -1;
	}
	else
	{
		cout << ans;
	}

	return 0;
}
