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
    int n;
    cin >> n;
    vector<int> d;
    for (int i = 1; i <= n / i; i ++) {
        if (n % i == 0) {
            d.push_back(i);
            if (n / i != i) d.push_back(n / i);
        }
    }
    sort(d.begin(), d.end());
    i64 ans = 0;
    for (int i = 1; i < d.size(); i ++) {
        ans += 1ll * (d[i] - d[i - 1]) * n / d[i - 1];
    }
    cout << ans + 1 << '\n';
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