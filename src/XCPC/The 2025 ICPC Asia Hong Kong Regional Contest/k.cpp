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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        b[i] = (i ? max(b[i - 1], a[i]) : a[i]);
    }
    int ans = 0;
    for (int i = 1; i < n; i ++) {
        vector<int> t(n);
        for (int j = 0; j < n; j ++) {
            t[j] = (j ? max(t[j - 1], a[(i + j) % n]) : a[(i + j) % n]);
        }
        if (t < b) b = t, ans = i;
    }
    
    cerr << ans << '\n';
    for (int i = 0; i < n; i ++) cerr << a[(i + ans) % n] << ' ';
    cerr << '\n';
    
    for (int i = 0; i < n; i ++) {
        cout << b[i] << ' ';
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