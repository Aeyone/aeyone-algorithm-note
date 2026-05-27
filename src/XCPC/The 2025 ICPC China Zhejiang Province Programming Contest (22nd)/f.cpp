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
    
    for (auto &e : a) {
        cin >> e;
    }
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        g[u].push_back(v);
    }

    auto run = [&](int col)-> bool {
        vector<int> cnt(n);
        vector<array<int, 4>> dis(n, {INF, INF, -1, -1}); // 0/2位置记录最短路信息，1/3记录次短路信息
        queue<array<int, 3>> q;
        for (int i = 0; i < n; i ++) if (a[i] == col) {
            cnt[i] = 1;
            dis[i][0] = 0;
            dis[i][2] = i;
            q.push({i, i, 0});
        }
        while (q.size()) {
            auto [u, st, sign] = q.front();
            q.pop();

            for (auto v : g[u]) if (cnt[v] == 0 || (cnt[v] == 1 && dis[v][2] != st)) {
                dis[v][cnt[v]] = dis[u][sign] + 1;
                dis[v][cnt[v] + 2] = st;
                if (a[v] != col) q.push({v, st, cnt[v]});
                cnt[v] ++;
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i ++) if (a[i] == col) {
            ok &= (dis[i][1] >= k);
        }
        return ok;
    };

    bool ok = true;
    for (int i = 1; i <= 50; i ++) {
        ok &= run(i);
    }
    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
}