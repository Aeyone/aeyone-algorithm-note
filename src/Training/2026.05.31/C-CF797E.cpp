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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    int q;
    cin >> q;
    const int M = 300;
    vector dp(n, vector<int>(M + 1));
    for (int k = 1; k <= M; k ++) {
        for (int i = n - 1; i >= 0; i --) {
            int ne = i + a[i] + k;
            dp[i][k] = (ne >= n ? 0 : dp[ne][k]) + 1;
        }
    }
    while (q --) {
        int p, k;
        cin >> p >> k;
        p --;
        if (k > M) {
            int ans = 0;
            while (p < n) {
                p = p + a[p] + k;
                ans ++;
            }
            cout << ans << '\n';
        } else {
            cout << dp[p][k] << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    // cin >> t;
    while (t --) {
        solve();
    }
}