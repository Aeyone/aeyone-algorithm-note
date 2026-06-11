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
    vector<int> a(2 * n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 0; i < n; i ++) {
        i64 ans = 0;
        int pre = a[i], suf = a[i + n - 1];
        int l = i, r = i + n - 1;
        while (l < r) {
            while (l < r && pre <= suf) {
                ans += pre;
                pre = std::max(pre, a[++ l]);
            }
            while (l < r && suf < pre) {
                ans += suf;
                suf = std::max(suf, a[-- r]);
            }
        }
        cout << ans << ' ';
    }
    cout << '\n';
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