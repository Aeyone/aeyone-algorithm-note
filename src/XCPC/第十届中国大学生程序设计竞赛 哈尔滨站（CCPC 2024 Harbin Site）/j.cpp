#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), x(m), t(m);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    auto b = a;
    vector<vector<int>> g(n);
    vector<int> cur(n);
    for (int i = 0; i < m; i ++) {
        cin >> x[i] >> t[i];
        t[i] --;
        g[t[i]].push_back(x[i]);
    }

    set<pair<int, int>> st;
    for (int i = 0; i < n; i ++) {
        if (g[i].size()) {
            st.insert({g[i][cur[i] ++], i});
        } else {
            st.insert({INFLL, i});
        }
    }

    int pos = 0;
    for (int i = 0; i < m; i ++) {
        while (st.size() && pos < x[i]) {
            auto [p, idx] = *st.begin();
            int d = min(x[i] - pos, a[idx]);
            pos += d;
            a[idx] -= d;
            st.erase(st.begin());
            if (a[idx] > 0 && p != x[i]) {
                st.insert({p, idx});
            }
        }
        if (!st.size() && pos < x[i]) break;
        int j = t[i];

        a[j] = b[j];
        if (cur[j] != (int)g[j].size()) {
            st.insert({g[j][cur[j] ++], j});
        } else {
            st.insert({INFLL, j});
        }
    }
    for (auto [d, e] : st) {
        pos += a[e];
    }
    cout << pos << '\n';

}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
}