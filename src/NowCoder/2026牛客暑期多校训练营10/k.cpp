#include <bits/stdc++.h>
using namespace std;

// using ll = long long;
#define int long long
#define pi acos(-1)
#define MOD 1000000007
#define mod 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve()
{
    int n;
    cin >> n;
    vector<int> g((1 << (3 * n))), dp((1 << (3 * n)), -INFLL);
    vector a(3 * n, vector<int>(3 * n));
    for (int i = 0; i < 3 * n; i++) {
        for (int j = 0; j < 3 * n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 3 * n; i++) {
        for (int j = i + 1; j < 3 * n; j++) {
            for (int k = j + 1; k < 3 * n; k++) {
                int cur = (1 << i) + (1 << j) + (1 << k);
                g[cur] = a[i][j] + a[i][k] + a[j][k];
            }
        }
    }
    vector<vector<int>> b(n + 1);
    for (int i = 0; i < (1 << (3 * n)); i++) {
        int c = __builtin_popcount(i);
        if (c % 3 == 0)
            b[c / 3].push_back(i);
    }
    dp[0] = 0;
    for (int i = 0; i <= n / 2; i++) {
        cerr << b[i].size() << '\n';
        for (auto mask : b[i]) {
            vector<int> tmp;
            for (int j = 0; j < 3 * n; j++) {
                if (!(mask >> j & 1)) {
                    tmp.push_back(j);
                }
            }
            int m = tmp.size();
            for (int i = 0; i < m; i++) {
                for (int j = i + 1; j < m; j++) {
                    for (int k = j + 1; k < m; k++) {
                        int cur = (1 << tmp[i]) + (1 << tmp[j]) + (1 << tmp[k]);
                        dp[mask ^ cur] = max(dp[mask ^ cur], dp[mask] + g[cur]);
                    }
                }
            }
        }
    }
    int ans = -INFLL;
    for (int i = 0; i < (1 << (3 * n)); i++) {
        if (__builtin_popcount(i) % (3 * ((n + 1) / 2)) == 0)
            ans = max(ans, dp[i] + dp[((1 << (3 * n)) - 1) ^ i]);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}