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
    i64 x, m;
    cin >> x >> m;
    i64 ans = 0;
    for(int y = 1; y <= min(x - 1, m); y ++) {
        ans += ((y ^ x) % y == 0);
    }
    i64 M = ((m >> (__lg(x) + 1)) << (__lg(x) + 1));    
    ans += M / x;
    if(m <= x - 1 || M == 0) {
        cout << ans + (M == 0 && m > x - 1) << '\n';
        return;
    }
    for(i64 y = M + 1; y <= m; y ++) {
        ans += ((y ^ x) % x == 0);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int _ = 1;
    // cin >> _;
    while (_ --){
        solve();
    }
}