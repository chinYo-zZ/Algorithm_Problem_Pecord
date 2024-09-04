#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
int L, N, K;
int MinAnswer;
vector<int> Position;

bool CheckMid(int mid) {
	int n = K;
	for (int i = 0; i < N - 1; i++) {
		int length = Position[i + 1] - Position[i];
		if (length > mid) {
			while (mid < length) {
				if (n == 0) {
					return false;
				}
				length -= mid;
				n--;
			}
		}
	}
	return true;
}

int main() {
	// TODO: Implement your code here
	cin >> L >> N >> K;
	MinAnswer = L;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		Position.push_back(x);
	}
	sort(Position.begin(), Position.end(), less<int>());

	int low = 0, high = L;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (CheckMid(mid)) {
			MinAnswer = mid;
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	cout << MinAnswer;
	return 0;
}
