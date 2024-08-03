#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int N = 1e6 + 5;

int n, m, ans;
int ClassroomAmount[N];
long long diff[N];
int num[N], l[N], r[N];

bool check(int _mid) {
	for (int i = 1; i <= n; i++) {
		diff[i] = 0;
	}
	for (int i = 1; i <= _mid; i++) {
		int _num = num[i], _l = l[i], _r = r[i];
		diff[_l] += _num;
		diff[_r + 1] -= _num;
	}

	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += diff[i];
		if (sum > ClassroomAmount[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> ClassroomAmount[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> num[i] >> l[i] >> r[i];
	}

	int low = 1, high = m;
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;

		if (check(mid)) {
			low = mid + 1;
		}
		else
		{
			ans = mid;
			high = mid - 1;
		}
	}

	if (ans == 0) {
		cout << ans;
	}
	else
	{
		cout << -1 << endl << ans;
	}
	return 0;
}
