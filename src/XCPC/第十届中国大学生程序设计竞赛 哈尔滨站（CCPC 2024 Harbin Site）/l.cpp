#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

vector<i64> fac, inv;

i64 qmi(i64 a, i64 b, int p){
    i64 res = 1;
    for( ;b ; b >>= 1, a = a * a % p) if(b & 1) {
        res = a * res % p;
    }
    return res;
}

void init(int n) {
    fac.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv.assign(n + 1, 1);
    inv[n] = qmi(fac[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

int C(int N, int M) {
    if (M > N || M < 0) {
        return 0;
    }
    return fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> siz(n);

    auto dfs1 = [&](this auto &&self, int u, int fa)-> void {
        siz[u] = 1;
        for (auto v : g[u]) if (v != fa) {
            self(v, u);
            siz[u] += siz[v];
        }
    };
    
    i64 ans = 0;
    auto dfs2 = [&](this auto &&self, int u, int fa, int up, int len)-> void {
        int down = siz[u] - 1;
        ans = (ans + (C(up, 2) + 2 * up + 1) * (C(down, 2) + 2 * down + 1) % MOD * len % MOD * len % MOD) % MOD;
        cerr << "u = " << u << " ans = " << ans << '\n';
        for (auto v : g[u]) if (v != fa) {
            self(v, u, up, len + 1);
        }
    };

    for (int i = 0; i < n; i ++) {
        siz.assign(n, 0);
        siz[i] = 1;
        cerr << "fa = " << i << '\n';
        for (auto v : g[i]) {
            dfs1(v, i);
            siz[i] += siz[v];
            dfs2(v, i, n - siz[v] - 1, 1);
        }
    }
    int tot = 2 * C(n, 2) * C(n, 2) % MOD;
    cerr << "ans = " << ans << '\n';
    cerr << "tot = " << tot << '\n';
    cout << ans * qmi(tot, MOD - 2, MOD) % MOD << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    init(1e6);
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
}