#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void Merge(vector<int> &nums, int left, int mid, int right)
{
    vector<int> tmp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
        {
            tmp[k++] = nums[i++];
        }
        else
        {
            tmp[k++] = nums[j++];
        }
    }

    while (i <= mid)
    {
        tmp[k++] = nums[i++];
    }
    while (j <= right)
    {
        tmp[k++] = nums[j++];
    }

    for (k = 0; k < tmp.size(); k++)
    {
        nums[left + k] = tmp[k];
    }
}

void MergeSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    MergeSort(nums, left, mid);
    MergeSort(nums, mid + 1, right);

    Merge(nums, left, mid, right);
}

int main()
{
    vector<int> vec{42, 17, 68, 23, 91, 5, 56, 84, 39, 77};
    MergeSort(vec, 0, vec.size() - 1);
    for (auto ele : vec)
    {
        cout << ele << " ";
    }
    return 0;
}
