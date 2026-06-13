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
    int n, k, m;
    cin >> n >> k >> m;
    vector<double> p(n);
    for (int i = 0; i < n; i ++) cin >> p[i];

    double cur = 0;
    for (int day = 1; day <= m; day ++) {
        double tmp = 0, pw = 1;
        for (int i = 0; i < n; i ++) {
            tmp += p[i] * pw;
            pw *= cur;
        }
        cur = tmp;
    }

    double ans = 1;
    for (int i = 0; i < k; i ++) {
        ans *= cur;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(7);
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
}
