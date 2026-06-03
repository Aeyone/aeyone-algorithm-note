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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < k; i ++) {
        int x;
        cin >> x;
        x --;
        a[x] = true;
    }
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        if (!a[u]) g[u].push_back(v);
        if (!a[v]) g[v].push_back(u);
    }
    vector<vector<int>> ans(n);
    vector<int> vis(n);
    queue<int> q;
    int T = 1;
    for (int i = 0; i < n; i ++) {
        if (!a[i]) {
            q.push(i);
            vis[i] = T ++;
            break;
        }
    }
    while (q.size()) {
        auto u = q.front();
        q.pop();

        for (auto v : g[u]) if (!vis[v]) {
            vis[v] = T ++;
            ans[u].push_back(v);
            q.push(v);
        }  
    }
    bool ok = true;
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        cerr << vis[i] << ' ';
        ok &= (vis[i] > 0);
        cnt += (ans[i].size() > 0);
    }
    cerr << '\n';
    if (!ok) {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
    vector<int> u(n);
    iota(u.begin(), u.end(), 0);
    sort(u.begin(), u.end(), [&](const int &a, const int &b)-> bool {
        return vis[a] < vis[b];
    });
    cout << cnt << '\n';
    for (auto e : u) {
        if (!ans[e].size()) continue;
        cout << e + 1 << ' ' << ans[e].size() << ' ';
        for (auto num : ans[e]) {
            cout << num + 1 << ' ';
        }
        cout << '\n';
    }
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