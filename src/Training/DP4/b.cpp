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
    vector<double> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i ++) {
        double p;
        cin >> p;
        for (int j = n; j >= 1; j --) {
            dp[j] = dp[j - 1] * p + dp[j] * (1 - p);
        }
        dp[0] *= (1 - p);
    }
    double ans = 0;
    for (int i = (n + 1) / 2; i <= n; i ++) {
        ans += dp[i];
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int t = 1;
    // cin >> t;
    while (t --) {
        solve();
    }
}