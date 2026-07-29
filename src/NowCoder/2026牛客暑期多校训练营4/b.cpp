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
 
void solve () {
    i64 p;
    cin >> p;
 
    if (p == 2) {
        cout << "12 1 71" << "\n";
        return;
    }
    if (p == 3) {
        cout << "19 2 89" << "\n";
        return;
    }
 
    i64 l = ceil (sqrt (p)), r = p - 1;
    i64 x = -1;
    while (l <= r) {
        i64 mid = (l + r) / 2;
        cerr << "l, r = " << l << ' ' << r << '\n';
        if (mid * mid - p > mid) {
            x = mid, l = mid - 1;
        } else {
            r = mid + 1;
        }
    }
    if (x == -1 || x * x - p > 1e12) {
        cout << "Impossible" << '\n';
    } else {
        cout << x << " " << x << " " << x * x - p << "\n";
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