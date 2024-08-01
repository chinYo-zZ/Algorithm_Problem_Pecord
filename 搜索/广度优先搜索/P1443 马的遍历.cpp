#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int mat[405][405];
int n, m, x, y;
int yy[] = { -1, 1, 2,2,1,-1,-2,-2 };
int xx[] = { -2,-2,-1,1,2, 2,1,-1 };
int main() {
	cin >> n >> m >> x >> y;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mat[i][j] = -1;
		}
	}
	queue<pair<int, int>> que;
	que.push(make_pair(x, y));
	mat[x][y] = 0;
	while (!que.empty()) {
		auto tmp = que.front();
		que.pop();
		for (int index = 0; index <= 7; index++) {
			int x_ = tmp.first + xx[index];
			int y_ = tmp.second + yy[index];
			if (x_ <= 0 || x_ > n || y_ <= 0 || y_ > m || mat[x_][y_] >= 0) {
				continue;//非法坐标
			}
			que.push(make_pair(x_, y_));
			mat[x_][y_] = mat[tmp.first][tmp.second] + 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << mat[i][j] << " ";
		}
	}
	return 0;
}
