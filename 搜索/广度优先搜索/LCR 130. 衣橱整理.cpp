class Solution {
public:
    int get(int x) {
        int res = 0;
        for (; x; x /= 10) {
            res += x % 10;
        }
        return res;
    }

    int wardrobeFinishing(int m, int n, int cnt) {
        if (!cnt) {
            return 1;
        }
        queue<pair<int, int>> Q;
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        Q.push(make_pair(0, 0));
        visited[0][0] = true;
        int ans = 1;
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            for (int i = 0; i < 2; i++) {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || visited[tx][ty] ||
                    get(tx) + get(ty) > cnt) {
                    continue;
                }
                Q.push(make_pair(tx, ty));
                visited[tx][ty] = true;
                ans++;
            }
        }
        return ans;
    }
};
