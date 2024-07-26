//牛客网 网易互娱雷火校园招聘试卷-游戏研发工程师（第一批）
#include <iostream>
#include <ostream>
#include <stack>
using namespace std;

struct Win {
    int id;
    int Xi;
    int Yi;
    int Wi;
    int Hi;

    bool InWin(int x, int y) {
        if (x >= Xi && y >= Yi) {
            if (x - Xi <= Wi && y - Yi <= Hi) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int n, m;
    stack<Win> Pri;
    stack<Win> Sec;
    cin >> n >> m;
    //初始化
    for (int i = 1; i <= n; i++) {
        Win win;
        cin >> win.Xi >> win.Yi >> win.Wi >> win.Hi;
        win.id = i;
        Pri.push(win);
    }

    for (int j = 0; j < m; j++) {
        int x, y;
        cin >> x >> y;
        Win tmp;
        bool bInitialize = false;
        while (!Pri.empty() && !Pri.top().InWin(x, y)) {
            Sec.push( Pri.top());
            Pri.pop();
        }
        if (!Pri.empty()) {
            cout << Pri.top().id << endl;
            tmp = Pri.top();
            bInitialize = true;
            Pri.pop();
        } else {
            cout << -1 << endl;
        }
        while (!Sec.empty()) {
            Pri.push(Sec.top());
            Sec.pop();
        }
        if (bInitialize) {
            Pri.push(tmp);
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
