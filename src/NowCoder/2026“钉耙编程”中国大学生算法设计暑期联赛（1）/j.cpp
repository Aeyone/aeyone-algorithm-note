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
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int cur = 1;
    int l = 1, r = n;
    while (r - l + 1 > 2) {
        if (cur) {
            if (a[l] > a[r]) {
                cout << "YES" << '\n';
                return;
            } else {
                a[l + 1] += a[l];
                a[r - 1] += (a[l] - 1);
                a[r] -= (a[l]- 1);
                a[l] = 0;
                l ++;
            }
        } else {
            if (a[r] > a[l]) {
                cout << "NO" << '\n';
                return;
            } else {
                a[l + 1] += (a[r] - 1);
                a[r - 1] += a[r];
                a[l] -= (a[r] - 1);
                a[r] = 0;
                r --;
            }
        }
        cur = !cur;
    }
    cout << (cur ? "YES" : "NO") << '\n';
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