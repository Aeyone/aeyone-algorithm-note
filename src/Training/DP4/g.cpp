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
    int test = 0;
#endif

const int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> g(n);
    vector<int> in(n);
    for (int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        g[v].push_back({u, w});
        in[u] ++;
    }
    vector<int> d = in;
    queue<int> q;
    q.push(n - 1);
    vector<double> dp(n);
    while (q.size()) {
        auto u = q.front();
        q.pop();
        for (auto [v, w] : g[u]) {
            dp[v] += (dp[u] + w) / d[v];
            in[v] --;
            if (!in[v]) q.push(v);
        }
    }
    cout << dp[0] << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(2);
    int t = 1;
    if (test) cin >> t;
    while (t --) {
        solve();
    }
}