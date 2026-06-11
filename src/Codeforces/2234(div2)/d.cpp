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
    int n, k;
    cin >> n >> k;
    string x, y, z(n, '0');
    cin >> x >> y;
    for (int i = 0; i < n; i ++) {
        int a = x[i] == '1', b = y[i] == '1';
        z[i] += (a ^ b);
    }
    i64 a = 1ll * ranges::count(x, '1') * ranges::count(x, '0');
    i64 b = 1ll * ranges::count(y, '1') * ranges::count(y, '0');
    i64 c = 1ll * ranges::count(z, '1') * ranges::count(z, '0');

    int tot = (1 << k) + 1;
    int q = tot / 3;
    i64 ans = (a + b + c) * q;
    if (~k & 1) ans += (a + b);

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
}