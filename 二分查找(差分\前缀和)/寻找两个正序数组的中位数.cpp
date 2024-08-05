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

	int Getk(vector<int>& n1, vector<int>& n2, int k) {
		int m = n1.size();
		int n = n2.size();
		int index1 = 0, index2 = 0;

		while (true) {
			if (index1 == m) {
				return n2[index2 + k - 1];
			}
			if (index2 == n) {
				return n1[index1 + k - 1];
			}
			if (k == 1) {
				return min(n1[index1], n2[index2]);
			}

			int newIndex1 = min(index1 + k / 2 - 1, m - 1);
			int newIndex2 = min(index2 + k / 2 - 1, n - 1);

			int pivot1 = n1[newIndex1];
			int pivot2 = n2[newIndex2];

			if (pivot1 <= pivot2) {
				k = k - (newIndex1 - index1 + 1);
				index1 = newIndex1 + 1;
			}
			else
			{
				k = k - (newIndex2 - index2 + 1);
				index2 = newIndex2 + 1;
			}
		}
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();
		int sum = n + m;
		if (sum % 2 == 1) {
			return (double)Getk(nums1, nums2, (sum + 1) / 2); // 奇数
		}
		else
		{
			return (Getk(nums1, nums2, sum / 2) + Getk(nums1, nums2, sum / 2 + 1)) / 2.f;
		}
	}
};

int main() {
	Solution* a = new Solution();
	vector<int> vec1{ 1,3 };
	vector<int> vec2{ 2 };
	a->findMedianSortedArrays(vec1,vec2);
}
