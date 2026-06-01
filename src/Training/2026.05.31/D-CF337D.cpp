#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<int>> g(n);
    vector<int> vis(n), dp(n, -INF), ans(n, -INF);
    for (int i = 0; i < m; i ++) {
        int x;
        cin >> x;
        x --;
        vis[x] = true;
    }
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto init = [&](this auto &&self, int u, int fa)-> void {
        if (vis[u]) dp[u] = 0;
        for (auto v : g[u]) if (v != fa) {
            self(v, u);
            dp[u] = max(dp[u], dp[v] + 1);
        }
    };
    init(0, -1);
    auto dfs = [&](this auto &&self, int u, int fa, int up)-> void { // 维护up[u]为所有除去u的子节点的其他节点的信息
        int m = g[u].size();
        vector<int> suf(m, -INF);
        for (int i = m - 1; i >= 1; i --) {
            suf[i - 1] = suf[i];
            auto v = g[u][i];
            if (v == fa) continue;
            suf[i - 1] = std::max(suf[i - 1], dp[v]);
        }
        int pre = -INF;
        for (int i = 0; i < m; i ++) {
            auto v = g[u][i];
            if (v == fa) continue;

            int exc = max(pre, suf[i]) + 1;
            int ne = max(up, exc) + 1;
            if (vis[v]) ne = max(ne, 0);
            ans[v] = max(dp[v], ne);
            
            pre = max(pre, dp[v]);
            self(v, u, ne);
        }
    };
    dfs(0, -1, (vis[0] ? 0 : -INF));
    ans[0] = dp[0];

    int res = 0;
    for (int i = 0; i < n; i ++) {
        res += (ans[i] <= d);
    }
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    // cin >> t;
    while (t --) {
        solve();
    }
}