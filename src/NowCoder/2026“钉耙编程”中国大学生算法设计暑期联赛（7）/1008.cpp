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
    int n, w;
    cin >> n >> w;
    string s;
    cin >> s;
    s = " " + s;
    cout << "Yes" << '\n';
    vector<i64> a(n);
    for (int i = n - 1; i >= 1; i --) {
        if (s[i] == '^' || s[i] == '|') {
            a[i] = 0;
        } else {
            a[i] = (1ll << 31) - 1;
        }
    }
    a[0] = w;
    for (int i = 0; i < n; i ++) {
        cout << a[i] << ' ';
    }
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