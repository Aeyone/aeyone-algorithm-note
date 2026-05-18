#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;

using i128 = __int128;
using u128 = unsigned __int128;

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] < siz[y]) {
            std::swap(x, y);
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    auto val = a;
    std::stable_sort(val.begin(), val.end());
    val.erase(std::unique(val.begin(), val.end()), val.end());

    int m = val.size();
    std::vector<int> id(val.back() + 1, -1);
    for (int i = 0; i < m; ++i) {
        id[val[i]] = i;
    }

    DSU d(m);
    std::vector<std::vector<std::array<int, 2>>> g(m);
    for (int i = val.back(); i >= 1; --i) {
        int u = -1;
        for (int j = i; j <= val.back(); j += i) {
            int v = id[j];
            if (v == -1) {
                continue;
            }
            if (u == -1) {
                u = v;
            } else if (d.merge(u, v)) {
                g[u].push_back({v, i});
                g[v].push_back({u, i});
            }
        }
    }

    std::vector<std::array<int, 22>> up(m);
    std::vector<std::array<int, 22>> min(m);
    std::vector<int> dep(m, 0);
    auto dfs = [&](auto &&self, int u, int p, int w) -> void {
        up[u][0] = p;
        min[u][0] = w;
        for (auto [v, w_] : g[u]) {
            if (v != p) {
                dep[v] = dep[u] + 1;
                self(self, v, u, w_);
            }
        }
    };
    dfs(dfs, 0, -1, 0);
    for (int i = 1; i < 22; ++i) {
        for (int u = 0; u < m; ++u) {
            if (up[u][i - 1] != -1) {
                up[u][i] = up[up[u][i - 1]][i - 1];
                min[u][i] = std::min(min[u][i - 1], min[up[u][i - 1]][i - 1]);
            } else {
                up[u][i] = -1;
            }
        }
    }

    auto query = [&](int u, int v) -> int {
        int ans = val[u];
        if (dep[u] < dep[v]) {
            std::swap(u, v);
        }
        int delta = dep[u] - dep[v];
        for (int i = 21; i >= 0; --i) {
            if ((delta >> i) & 1) {
                ans = std::min(ans, min[u][i]);
                u = up[u][i];
            }
        }
        if (u == v) {
            return ans;
        }
        for (int i = 21; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                ans = std::min(ans, min[u][i]);
                ans = std::min(ans, min[v][i]);
                u = up[u][i];
                v = up[v][i];
            }
        }
        ans = std::min(ans, min[u][0]);
        ans = std::min(ans, min[v][0]);
        return ans;
    };

    while (q--) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        
        std::cout << query(id[a[x]], id[a[y]]) << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}