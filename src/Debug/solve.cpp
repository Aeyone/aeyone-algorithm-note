#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
    int x, y;
    cin >> x >> y;
    int X = x, Y = y;
    int z = x & y;
    int pre = 0;
    int p = x ^ z, q = y, cur = z;
    for (int i = 32; i >= 0; i --) {
        if ((x >> i & 1) == (y >> i & 1)) {
            if (x >> i & 1) {
                pre += (1ll << i);
                x -= (1ll << i);
            } else {
                int cx = (1ll << i) - (x % (1ll << i));
                int cy = (1ll << i) - (y % (1ll << i));
                int cost = pre + min(cx, cy);
                if (cost < cur) {
                    if (cx <= cy) {
                        p = (x >> i) + 1 << i;
                        q = y;
                    } else {
                        p = x;
                        q = (y >> i) + 1 << i;
                    }
                    cur = cost;
                }
                if (i < __lg(z)) {
                    x += (1ll << i);
                    pre -= (1ll << i);
                }
            }
        }
    }
    int ans = 0, check = 0;
    if (pre <= cur) {
        ans += abs(X - x) + abs(Y - y);
        check = x & y;
    } else {
        ans += abs(X - p) + abs(Y - q);
        check = x & y;
    }
    cout << ans << ' ' << check << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int _ = 1;
    // cin >> _;
    while (_ --) {
        solve();
    }
}