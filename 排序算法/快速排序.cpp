#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Swap(vector<int> &_vec, int i, int j)
{
    int tmp = _vec[i];
    _vec[i] = _vec[j];
    _vec[j] = tmp;
}

int MidNum(vector<int> &_vec, int l, int mid, int r)
{
    vector<int> tmp{_vec[l], _vec[mid], _vec[r]};
    sort(tmp.begin(), tmp.end(), [](int a, int b) -> bool
         { return a > b; });
    if (tmp[1] == _vec[l])
    {
        return l;
    }
    if (tmp[1] == _vec[mid])
    {
        return mid;
    }
    if (tmp[1] == _vec[r])
    {
        return r;
    }
}

int SwapSort(vector<int> &_vec, int left, int right)
{

    int Target = MidNum(_vec, left, (left + right) / 2, right);
    swap(_vec[left], _vec[Target]);
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && _vec[j] >= _vec[left])
        {
            j--;
        }
        while (i < j && _vec[i] <= _vec[left])
        {
            i++;
        }

        swap(_vec[i], _vec[j]);
    }
    swap(_vec[i], _vec[left]);
    return i;
}

void QuickSort(vector<int> &_vec, int left, int right)
{
    while (left < right)
    {
        int Pivot = SwapSort(_vec, left, right);
        if (Pivot - left < right - Pivot)
        {
            QuickSort(_vec, left, Pivot - 1);
            left = Pivot + 1;
        }
        else
        {
            QuickSort(_vec, Pivot + 1, right);
            right = Pivot - 1;
        }
    }
}

int main()
{
    vector<int> vec{34, 78, 12, 56, 90, 22, 47, 63, 85, 19};
    QuickSort(vec, 0, vec.size() - 1);
    for (auto ele : vec)
    {
        cout << ele << " ";
    }
    return 0;
}
