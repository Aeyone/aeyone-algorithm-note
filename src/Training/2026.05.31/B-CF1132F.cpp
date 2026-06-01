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
    string s;
    cin >> s;
    vector dp(n, vector<int>(n, INF));
    for (int i = 0; i < n; i ++) dp[i][i] = 1;
    for (int len = 2; len <= n; len ++) {
        for (int l = 0, r = len - 1; r < n; l ++, r ++) {
            for (int k = l; k < r; k ++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] - (s[l] == s[r]));
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
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