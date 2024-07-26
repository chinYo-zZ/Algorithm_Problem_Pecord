#include<iostream>
#include <string>
using namespace std;
//储存单词
string word[25];
//字符串个数 | 记录字符串使用次数（不能超过2）| 答案
int n, mark[25] = { 0 },ans = 0;

string concatenation(string s1, string s2) {
    int len1 = s1.size(), len2 = s2.size();
    //再两个串长度内循环
    for (int i = 1; i < len1 && i < len2; i++) {
        //结尾开始第i个，开头开始第i个（substr从value1开始截取value2长度的子串）
        if (s1.substr(len1 - i, i) == s2.substr(0, i)) {
            return s1.substr(0, len1 - i) + s2;
        }
    }
    return "0";
}

void dfs(string drag) {
    //新添加后对比目前ans大小，并非结束函数
    if (drag.size() > ans) {
        ans = drag.size();
    }
    for (int i = 0; i < n; i++) {
        if (mark[i] == 2) {
            continue;
        }
        //循环进行拼接
        string s = concatenation(drag, word[i]);
        if (s != "0") {
            mark[i]++;
            dfs(s);
            mark[i]--;
        }
    }
}


int main()
{
    //开头要求的字母
    char c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word[i];
    }
    cin >> c;
    for (int i = 0; i < n; i++) {
        if (word[i][0] == c) {
            //标记本次循环的单词使用一次
            mark[i]++;
            //开始搜索
            dfs(word[i]);
            //回退本次使用：回溯
            mark[i]--;
        }
    }
    cout << ans << endl;
    return 0;
}
