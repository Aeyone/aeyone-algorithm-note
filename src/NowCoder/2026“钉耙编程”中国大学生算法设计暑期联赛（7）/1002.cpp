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
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector dp(2, vector<array<int, 2>> (1 << 4, {INF, INF}));
    int mx = 0;
    for (int i = 2; i <= n; i ++) {
        int cur = ((s[i - 1] == '1') << 1) + (s[i] == '1');
        mx |= (1 << cur);
    }
    for (int i = 1; i <= n; i ++) {
        dp[i & 1] = dp[i - 1 & 1];
        int cur = (s[i] == '1');
        dp[i & 1][0][cur] = 1;
        for (int la = 0; la <= 1; la ++) {
            for (int mask = 0; mask < 1 << 4; mask ++) {
                int st = (la << 1 | cur);
                dp[i & 1][mask | (1 << st)][cur] = min(
                    dp[i & 1][mask | (1 << st)][cur],
                    dp[i - 1 & 1][mask][la] + 1
                );
            }
        }
    }
    cout << min(dp[n & 1][mx][0], dp[n & 1][mx][1]) << '\n';
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