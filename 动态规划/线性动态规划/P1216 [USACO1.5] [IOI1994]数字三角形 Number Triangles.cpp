#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int mat[1005][1005];
int n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = n-1; 1<=i; i--) {
		for (int j = 1; j <= i; j++) {
			//从下往上加
			mat[i][j] += max(mat[i + 1][j], mat[i + 1][j + 1]);
		}
	}
	cout << mat[1][1] << endl;
	return 0;
}
