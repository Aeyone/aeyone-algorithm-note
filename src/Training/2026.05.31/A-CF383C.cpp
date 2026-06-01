#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n + 1, T{});
    }

    void modify(int x, const T &v) { // 单点修改
        while(x <= n) {
            a[x] += v, x += x & -x;
        }
    }

    void modify(int l, int r, const T &v) { // 区间修改(差分优化)
        modify(l, v), modify(r + 1, -v);
    }
    
    T query(int x) {// 查询1~x的和 or 单点查询(差分优化)
        T ans{};
        while(x > 0) {
            ans += a[x], x -= x & -x;
        }
        return ans;
    }
    // 1-based
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), dfn(n), dep(n), siz(n);
    vector<vector<int>> g(n);
    vector fw(2, Fenwick<int>(n));

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int T = 1;
    auto dfs = [&](this auto &&self, int u, int fa = -1)-> void {
        dfn[u] = T ++;
        siz[u] = 1;
        for (auto v : g[u]) if (v != fa) {
            dep[v] = dep[u] + 1;
            self(v, u);
            siz[u] += siz[v];
        }
    };
    dfs(0);
    for (int i = 0; i < n; i ++) {
        int x = dfn[i];
        fw[0].modify(x, x, a[i]);
        fw[1].modify(x, x, a[i]);
    }
    while (m --) {
        int c;
        cin >> c;
        if (c == 1) {
            int u, val;
            cin >> u >> val;
            u --;
            fw[dep[u] & 1].modify(dfn[u], dfn[u] + siz[u] - 1, val);
            fw[~dep[u] & 1].modify(dfn[u], dfn[u] + siz[u] - 1, -val);
        } else {
            int u;
            cin >> u;
            u --;
            cout << fw[dep[u] & 1].query(dfn[u]) << '\n';
        }
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