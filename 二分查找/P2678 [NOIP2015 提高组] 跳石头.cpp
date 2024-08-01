#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int l, n, m;
int num[50005] = { 0 };
int main()
{
	cin >> l >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}


	int low = 0, high = l+1;
	while (high - low > 1)
	{
		int mid = (high - low) / 2 + low;
		int k = 0;
		int sum = 0; //移走石头数量
		bool flag = false;
		for (int i = 1; i <= n; i++) {
			int dis = num[i] - k;
			if (dis >= mid) {
				k = num[i];
			}
			else
			{
				sum++;
				if (sum > m) {
					flag = true;
					break;
				}
			}
		}
		if (flag) {
			high = mid;
		}
		else
		{
			low = mid;
		}
		
	}

	cout << low << endl;

	return 0;
}
