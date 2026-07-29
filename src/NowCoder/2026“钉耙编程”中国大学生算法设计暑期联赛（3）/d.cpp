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
    int test = 1;
#endif

const int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ch(n), w(m);
    for (int i = 0; i < n; i ++) {
        int len;
        cin >> len;
        ch[i].assign(len, 0);
        for (int j = 0; j < len; j ++) {
            cin >> ch[i][j];
            ch[i][j] --;
        }
    }
    for (int i = 0; i < m; i ++) {
        int len;
        cin >> len;
        w[i].assign(len, 0);
        for (int j = 0; j < len; j ++) {
            cin >> w[i][j];
        }
    }
    vector<int> toy(m), vis(n);
    int cur = n;
    i64 ans = 0;
    while (cur --) {
        vector<pair<vector<int>, pair<int, int>>> v;
        for (int i = 0; i < n; i ++) {
            if (vis[i]) continue;
            int len = ch[i].size();
            vector<array<int, 2>> vv = {{INF, ch[i][0]}};
            vector<int> d;
            for (int j = 0; j < len; j ++) {
                int u = ch[i][j];
                vv.push_back({w[u][toy[u]], u});
            }
            sort(vv.begin(), vv.end());
            for (int j = 1; j < vv.size(); j ++) {
                d.push_back(vv[j][0] - vv[j - 1][0]);
            }
            v.push_back({d, {vv[0][1], i}});
        }
        sort(v.begin(), v.end(), greater<pair<vector<int>, pair<int, int>>>{});
        int u = v[0].second.first;
        int child = v[0].second.second;
        vis[child] = true;
        ans += w[u][toy[u] ++];
        // cerr << "idx[0] = " << idx[0] << ' ';
        // cerr << "ans = " << ans << '\n';
    }
    cout << ans << '\n';
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