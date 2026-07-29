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
    vector<int> a(n);
    if (n & 1) {
        a[0] = n / 2 + 1;
        for (int i = n - 1, x = n / 2 + 2;i >= 2;i -= 2, x++) {
            a[i] = x;
        }
        for (int i = n - 2, x = 1;i >= 1;i -= 2, x++) {
            a[i] = x;
        }
    }
    else {
        for (int i = 0, x = n / 2 + 1;i < n - 1;i += 2, x++) {
            a[i] = x;
        }
        for (int i = n - 1, x = 1;i >= 1;i -= 2, x++) {
            a[i] = x;
        }
    }
    int idx = 0;
    while (a[idx] != 1)idx++;
    for (int i = 0;i < n;i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
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