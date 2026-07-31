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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 2, vector<int>(m + 2));
    auto b = a;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int k = a[1][1];
    if (n >= 2 && m >= 2) {
        k += a[2][1] + a[1][2] - 2 * a[1][1];
    }

    for (int i = 1; i <= n + 1; i++) {
        a[i][m + 1] = k;
    }
    for (int i = 1; i <= m + 1; i++) {
        a[n + 1][i] = k;
    }
    // cerr << "k = " << k << '\n';
    int ok = 1;
    b[1][1] = k - a[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == n && j == m) continue;
            int d = k - a[i][j + 1] - b[i][j + 1];

            if (d >= 0 && b[i][j] >= d) {
                b[i][j] -= d, b[i][j + 1] += d;
            } else {
                ok = false;
            }
            if ((a[i + 1][j] + b[i][j] <= k && j > 1) || (a[i + 1][j] + b[i][j] == k && j == 1)) {
                b[i + 1][j] = b[i][j];
            } else {
                ok = false;
            }
            if (!ok) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    cout << k - a[1][1] << '\n';
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