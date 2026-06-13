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
    vector<double> dp(n + 1); // dp[i]表示已经见过i个面的期望次数
    for (int i = n - 1; i >= 0; i --) {
        dp[i] = 1 + dp[i + 1] * (n - i) / n;
        dp[i] /= 1 - 1.0 * i / n;
    }
    cout << dp[0] << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(2);
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
}
