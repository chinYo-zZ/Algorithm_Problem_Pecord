#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <memory>
#include <string.h>
using namespace std;
const int MAX_Value = 0x3f3f3f3f;

int n, m;
int main()
{
	cin >> n >> m;
	vector<vector<int>> diff(n + 2, vector<int>(n + 2, 0));
	for (int i = 1; i <= m; i++) {
		int x1, y1, x2, y2;
		// 1 2   1 4
		cin >> x1 >> y1 >> x2 >> y2;

		for (int row = x1; row <= x2; row++) {
			diff[row][y1]++;
			diff[row][y2 + 1]--;
		}
	}

	for (int row = 1; row <= n; row++) {
		int PreSum = 0;
		for (int col = 1; col <= n; col++) {
			int out = diff[row][col] + PreSum;
			PreSum = out;
			cout << out << " ";
		}
		cout<<endl;
	}
	return 0;
}
