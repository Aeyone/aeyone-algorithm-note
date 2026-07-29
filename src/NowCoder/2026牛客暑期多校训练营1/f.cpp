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
    int test = 0;
#endif

const int MOD = 998244353;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> p(n), idx(n);
    for (int i = 0; i < n; i ++) {
        cin >> p[i];
        idx[p[i]] = i;
    }
    i64 cost = 1ll * (x - p[k]) * (k - idx[x]);
    int d = abs(x - p[k]);
    swap(p[k], p[idx[x]]);

    bool ok = false;
    for (int i = 0; i + d < n; i ++) {
        if (i == k || i + d == k) continue;
        if (cost + 1ll * d * (p[i] - p[i + d]) == 0) {
            ok = true;
            swap(p[i], p[i + d]);
            break;
        }
    }
    if (!ok) {
        cout << -1 << '\n';
        return;
    }
    for (auto e : p) cout << e << ' ';
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