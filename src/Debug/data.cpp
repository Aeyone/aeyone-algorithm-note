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
    i64 n = rand(1, 20), m = rand(1, 20);
    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int x = rand(1, 5);
            string s = "knare";
            if (x == 1) {
                cout << 'x';
            } else {
                cout << s[rand(0, 4)];
            }
        }
        cout << '\n';
    }
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