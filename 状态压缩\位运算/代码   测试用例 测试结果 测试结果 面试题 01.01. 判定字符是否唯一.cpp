#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
	bool isUnique(string astr) {
		int n = astr.size();
		int x = 0;
		for (int i = 0; i < n; i++) {
      // 通过将0001左移来实现对特定字母的储存和检查，字符减‘a’实为ascll码，a-a不动，c-a左移两位变 0100
			if (x & (1 << astr[i] - 'a')) {
				return false;
			}
			else
			{
        // 与运算有一则一
				x = x | (1 << astr[i] - 'a');
			}
		}
		return true;
	}
};

int main() {
	return 0;
}
