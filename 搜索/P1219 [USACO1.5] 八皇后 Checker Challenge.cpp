#include<iostream>

using namespace std;

int n, a[15];
//列标记，对角线标记
bool b[15], c[200], d[200];
int index = 20;

void DFS(int i) {
    //循环n次
    for (int j = 1; j <= n; j++) {
        //判断是否能放置
        if (b[j] && c[i + j] && d[i - j + index]) {
            //第i个在第i行，第j列
            a[i] = j;
            //标记列为不可放置
            b[j] = false;
            //标记左上斜对角线为不可放置
            c[i + j] = false;
            //标记右上斜对角线为不可放置，index为防溢出
            d[i - j + index] = false;
            if (i < n) {
                DFS(i + 1);
            }
            else {
                for (int in = 1; in <= n; in++) {
                    cout << a[in] << " ";
                }
                cout << "\n";
                a[0]++;//a[0]没用到，合法次数就放这了
            }
            b[j] = true;
            c[i + j] = true;
            d[i - j + index] = true;
        }
    }
}

int main()
{
    fill(b, b + 15, true);
    fill(c, c + 200, true);
    fill(d, d + 200, true);
    cin >> n;
    //开始放置第一个皇后
    DFS(1);
    cout << a[0];
    return 0;
}
