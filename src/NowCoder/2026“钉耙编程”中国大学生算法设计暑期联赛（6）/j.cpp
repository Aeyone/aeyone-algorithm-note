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
    i64 x, y;
    cin >> x >> y;
    i64 k = max(0ll, x - 1) / (y + 1);
    i64 r = max(0ll, x - 1) % (y + 1);
    i64 n = x + y;
    i64 ans = r * (k + 2) * ((n - (k + 2)) + (n - r * (k + 2))) / 2;
    i64 m = n - r * (k + 2);
    ans += (y - r) * (k + 1) * ((m - (k + 1)) + (m - (y - r) * (k + 1))) / 2;
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