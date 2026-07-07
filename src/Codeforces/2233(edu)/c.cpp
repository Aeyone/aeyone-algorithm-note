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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> l, r;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '(') l.push_back(i);
        else r.push_back(i);
    }
    reverse(r.begin(), r.end());
    pair<int, vector<int>> ans = {INF, {}};
    for (int i = k, j = 0; i >= 0; i --, j ++) {
        if (l.size() < i || r.size() < j) continue;
        vector<int> vis(n);
        for (int p = 0; p < i; p ++) vis[l[p]] = true;
        for (int p = 0; p < j; p ++) vis[r[p]] = true;

        int len = 0, pre = 0;
        for (int p = 0; p < n; p ++) if (!vis[p]) {
            if (s[p] == '(') pre ++;
            else if (pre) pre --, len += 2;
        }
        if (len < ans.first) {
            ans = {len, vis};
        }
    }
    for (auto e : ans.second) cout << e;
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