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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int N = s.size();
    s = " " + s;
    vector<array<int, 3>> tot;
    vector<int> a(N + 1), v;
    for (int i = 1; i <= N; i ++) {
        a[i] = (s[i] == '1');
        if (a[i]) v.push_back(i);
    }
    auto dfs = [&](auto &&self, vector<int> v)-> void {
        if (v.size() <= 1) return;
        if (v.size() & 1) v.push_back(0);
        int n = v.size();
        vector<int> vv, res;
        for (int i = 0; i < n; i += 2) {
            int x = v[i] ^ v[i + 1];
            if (v[i + 1] != 0) {
                tot.push_back({v[i], v[i + 1], x});
                a[v[i]] = !a[v[i]];
                a[v[i + 1]] = !a[v[i + 1]];
                a[x] = !a[x];
            }
            vv.push_back(x);
        }
        for (auto e : vv) if (a[e]) {
            res.push_back(e);
        }
        self(self, res);
    };
    dfs(dfs, v);
    vector<int> ans(N + 1), vis(N);
    for (auto [x, y, z] : tot) {
        if (!ans[x]) ans[x] = y;
        else if (!ans[y]) ans[y] = z;
        else ans[z] = x;
    }
    for (int i = 1; i <= N; i ++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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