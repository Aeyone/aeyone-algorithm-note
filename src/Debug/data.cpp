#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

static mt19937_64 rng (
    chrono::steady_clock::now().time_since_epoch().count()
);
#define rand(l, r) (uniform_int_distribution<long long>((l),(r))(rng))

void solve() {
    i64 n = rand(1, 20);
    string s(n, 'i');
    for (int i = 0; i < n; i ++) {
        if (rand(1, 3) == 1) {
            s[i] = 'w';
        }
    }
    cout << s << '\n';
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
