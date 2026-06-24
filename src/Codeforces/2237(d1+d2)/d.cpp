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
    string s;
    cin >> s;
    s = " " + s;
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i ++) {
        sum[i] = (sum[i - 1] + (s[i] == '0' ? -1 : 1) + 3) % 3;
    }
    i64 ans = 1ll * n * (n - 1) / 2 + n;
    int tot[3] {};
    for (int i = n; i >= 1; i --) {
        tot[sum[i]] ++;
        int tmp[3] {};
        for (int j = 0; j < 3; j ++) {
            tmp[(j - sum[i - 1] + 3) % 3] = tot[j];
        }
        ans -= tmp[0];
    }
    vector<int> a(n + 1);
    a[n] = 1;
    for (int i = n - 1; i >= 1; i --) {
        a[i] = (s[i] == s[i + 1] ? 1 : a[i + 1] + 1);
        ans -= (a[i] - 1) / 2;
    }
    cout << ans << '\n';
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