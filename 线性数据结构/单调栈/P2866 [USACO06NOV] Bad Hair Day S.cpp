#include<iostream>
#include <string>
#include <stack>
using namespace std;
int n;
stack<int> Hight; // 单调栈
long long ans = 0;//会溢出

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int niu;
		cin >> niu;
		// 把比将入栈的牛矮的出栈，剩下的就是能看到这个将要入栈的牛的牛
		while (!Hight.empty() && Hight.top() <= niu)
		{
			Hight.pop();
		}
		// 先计算能看到的牛再入栈
		ans += Hight.size();
		Hight.push(niu);
	}
	cout << ans << endl;
	return 0;
}
