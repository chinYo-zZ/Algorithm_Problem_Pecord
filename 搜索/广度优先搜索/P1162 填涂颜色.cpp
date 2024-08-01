#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int mat[40][40] = { 0 };
int n;
int yy[] = { 0,1,0,-1 };
int xx[] = { -1,0,1,0 };
int main() {
  //秘籍就是在外围加一圈
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}
	queue<pair<int, int>> que;
	que.push(make_pair(0, 0));
	mat[0][0] = -1;
	while (!que.empty()) {
		auto tmp = que.front();
		que.pop();
		for (int index = 0; index <= 3; index++) {
			int x = tmp.first + xx[index];
			int y = tmp.second + yy[index];
			if (x<0 || x>n+1 || y<0 || y>n+1 || mat[x][y] == -1 || mat[x][y] == 1) {
				continue;//非法坐标
			}
			que.push(make_pair(x, y));
			mat[x][y] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			switch (mat[i][j])
			{
			case -1:
				cout << 0 << " ";
				break;
			case 1:
				cout << 1 << " ";
				break;
			case 0:
				cout << 2 << " ";
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
	return 0;
}
