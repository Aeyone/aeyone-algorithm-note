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
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    vector<vector<i128>> dp(2, vector<i128>(61, (i128)INF * INFLL)); // dp[i][j]为考虑前i个长度为j的前缀和的最小值
    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= 60; j ++) {
            dp[i & 1][j] = dp[i - 1 & 1][j];
            if (dp[i - 1 & 1][j - 1] <= a[i]) {
                dp[i & 1][j] = min(dp[i & 1][j], dp[i - 1 & 1][j - 1] + a[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 60; i ++) {
        if (dp[n & 1][i] < (i128)INF * INFLL) ans = i;
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