#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
    int ans = 0;
    vector<array<int, 2>> bit(31);
    for(int i = 0; i <= 10; i ++){
        for(int j = 0; j < 5; j ++){
            bit[j][(i >> j & 1)] ++;
        }
        // ans += (7 ^ i);
    }
    for(int i = 0; i < 5; i ++){
        cout << bit[i][0] << ' ' << bit[i][1] << '\n';
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_ --){
        solve();
    }
}