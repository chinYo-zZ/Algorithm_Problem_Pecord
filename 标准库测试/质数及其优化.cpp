#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N = 453;
	int sumStep = 0; // 统计迭代次数

	cout << 2 << endl; // 2 是质数
	for (int i = 3; i < N; i += 2) {
		bool flag = true;    // 假设是质数
		int jStop = sqrt(i); // 终止条件
		for (int j = 3; j <= jStop; j += 2) {
			sumStep = sumStep + 1;
			if (!(i % j)) { // 找到能被整除的
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << i << endl;
		}
	}
	cout << "sumStep: " << sumStep << endl;

	return 0;
}
