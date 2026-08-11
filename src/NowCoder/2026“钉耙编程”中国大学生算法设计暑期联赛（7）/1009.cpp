#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

#ifdef LOCAL 
    int test = 1;
#else
    int test = 1;
#endif

const int MOD = 998244353;

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> d(m + 1), c(m + 1);
    for (int i = 1; i <= m; i ++) {
        cin >> d[i] >> c[i];
    }
    vector<int> K(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> K[i];
    }
    vector dp(2, vector<vector<int>> (n + 1, vector<int>(m + 1, INFLL)));
    vector l(m + 1, vector<int>(m + 1, -1)), r(m + 1, vector<int>(m + 1, -1));
    dp[1][s][0] = 0;
    l[0][0] = s, r[0][0] = s;
    for (int i = 1; i <= m; i ++) {
        auto L = l[i], R = r[i];
        for (int k = 0; k < m; k ++) {
            
            for (int j = L[k]; j <= R[k]; j ++) {

            }
            for (int j = max(1ll, L[k] - d[i]); j <= min(n, R[k] + d[i]); j ++) {
                if (j == max(1ll, L[k] - d[i]) || j == min(n, R[k] + d[i])) {
                    dp[i & 1]
                }
            }
        }
    }
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