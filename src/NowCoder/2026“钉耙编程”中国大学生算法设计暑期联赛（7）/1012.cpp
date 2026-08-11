#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

#ifdef LOCAL 
    int test = 1;
#else
    int test = 1;
#endif

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    int idx = n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i ++) {
        int p;
        cin >> p;
        p --;
        g[p].push_back(i);
        g[i].push_back(p);
    }

    vector<int> h(n), dep(n);
    int ans = 0;
    auto dfs1 = [&](auto &&self, int u, int fa)-> void {
        set<array<int, 2>> st;
        for (int v : g[u]) if (v != fa) {
            dep[v] = dep[u] + 1;
            ans += dep[v];
            self(self, v, u);
            st.insert({h[v], v});
        }
        while (st.size() > 2) {
            auto e1 = *st.begin();
            st.erase(st.begin());
            auto e2 = *st.begin();
            st.erase(st.begin());
            h.push_back(max(e1[0], e2[0]) + 1);
            st.insert({h[idx], idx});
            idx ++;
        }
        if (st.size()) {
            h[u] = (*st.rbegin())[0] + 1;
        }
    };
    dfs1(dfs1, 0, -1);

    idx = n;
    vector<int> cnt(n, 1);
    auto dfs2 = [&](auto &&self, int u, int fa)-> void {
        set<array<int, 2>> st;
        for (int v : g[u]) if (v != fa) {
            self(self, v, u);
            cnt[u] += cnt[v];
            st.insert({cnt[v], v});
        }
        while (st.size() > 2) {
            auto e1 = *st.begin();
            st.erase(st.begin());
            auto e2 = *st.begin();
            st.erase(st.begin());
            cnt.push_back(e1[0] + e2[0]);
            st.insert({cnt[idx], idx});
            ans += cnt[idx ++];
        }
    };
    dfs2(dfs2, 0, -1);
    cout << h[0] << ' ' << ans << '\n';
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