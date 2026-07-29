#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

#ifdef LOCAL 
    int test = 1;
#else
    int test = 1;
#endif

const int MOD = 998244353;

int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m)), cnt(n, vector<int>(m)), st(n, vector<int>(m));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }
    queue<array<int, 2>> q;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            for (int k = 0; k < 4; k ++) {
                int a = i + dx[k], b = j + dy[k];
                if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] < g[i][j]) continue;
                cnt[i][j] ++;
            }
            if (!cnt[i][j]) {
                q.push({i, j});
            }
        }
    }
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] < g[x][y]) continue;
            st[x][y] |= (st[a][b] == 0);
        }
        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] > g[x][y]) continue;
            cnt[a][b] --;
            if (!cnt[a][b]) {
                q.push({a, b});
            }
        }
    }
    int t;
    cin >> t;
    while (t --) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        cout << (st[x][y] ? "First" : "Second") << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    if (test) cin >> t;
    while (t --) {
        solve();
    }
}