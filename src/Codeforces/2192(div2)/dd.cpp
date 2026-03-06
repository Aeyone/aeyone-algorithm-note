#include <bits/stdc++.h>

#define x first
#define y second

using i64 = long long;
using PII = std::pair<int, int>;

void solve(void) {
    int n; std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    std::vector G(n + 1, std::vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    std::vector<int> dep(n + 1);
    std::vector<i64> s(n + 1);
    std::vector<i64> total(n + 1), f(n + 1);
    auto dfs = [&](auto && self, int u, int fa) -> void {
        s[u] = a[u];
        i64 maxn = 0;    
        for (auto v : G[u]) {
            if (v == fa) continue;
            self(self, v, u);
            f[u] = std::max({f[u], maxn * (dep[v] + 1), dep[u] * s[v], f[v]});
            // std::cout<<u<<" "<<maxn<<" "<<dep[v]+1<<" "<<dep[u]<<" "<<s[v]<<" "<<f[v]<<'\n';
            dep[u] = std::max(dep[u], dep[v] + 1);
            maxn = std::max(maxn, s[v]);
            s[u] += s[v];
            total[u] += total[v] + s[v];
        }
    };
    dfs(dfs, 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cout << total[i] + f[i] << ' ';
    }
    std::cout << '\n';
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) solve();

    return 0;
}