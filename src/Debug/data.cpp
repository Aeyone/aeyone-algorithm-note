#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

static mt19937_64 rng (
    chrono::steady_clock::now().time_since_epoch().count()
);
#define randll(l, r) (uniform_int_distribution<long long>((l),(r))(rng))

void solve() {
    i64 n = randll(8, 15), m = 4;    
    cout << n << ' ' << m << '\n';
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