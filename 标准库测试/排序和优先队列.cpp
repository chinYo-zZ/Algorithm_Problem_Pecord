#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Item
{
    int value;
    int priority;

    Item(int v, int p) : value(v), priority(p) {}
};

struct CompareItem
{
    bool operator()(const Item &a, const Item &b)
    {
        return a.priority > b.priority;
    }
};

bool CItem(const Item &a, const Item &b)
{
    return a.priority > b.priority;
}


int main()
{
    vector<int> test{3, 7, 2, 465, 23, 7, 7, 56, 967956, 34};

    vector<Item> pq;
    pq.push_back(Item(1, 3));
    pq.push_back(Item(2, 5));
    pq.push_back(Item(3, 1));
    sort(pq.begin(), pq.end(), CItem);
    cout << pq[0].value << endl;
    cout << pq[1].value << endl;
    cout << pq[2].value << endl;

    for (auto ele : test)
    {
        cout << ele << " ";
    }

    return 0;
}
