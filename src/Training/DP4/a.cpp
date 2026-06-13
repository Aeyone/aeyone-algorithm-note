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
    int n, m;
    cin >> n >> m;
    vector<double> dp(n + 1);
    for (int i = 0; i < m; i ++) {
        int w;
        double p;
        cin >> w >> p;
        for (int j = n; j >= w; j --) {
            dp[j] = max(dp[j], dp[j - w] + (1 - dp[j - w]) * p);
        }
    }
    cout << dp[n] * 100 << "%" << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(1);
    int t = 1;
    // cin >> t;
    while (t --) {
        solve();
    }
}