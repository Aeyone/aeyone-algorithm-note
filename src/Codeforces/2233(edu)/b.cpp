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
    int n;
    cin >> n;
    vector<int> a = {1, 1, 2, 1, 0, 0, 1};
    for (int i = 2; i <= n; i ++) {
        int siz = a.size();
        a[siz - 2] = a[siz - 3] = i;
        if (i != 2) {
            a.push_back(i);
        }
        if (i != n) {
            a.push_back(0);
            a.push_back(0);
            a.push_back(i);
        }
    }
    cout << n << ' ';
    for (auto e : a) cout << e << ' ';
    cout << '\n';
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