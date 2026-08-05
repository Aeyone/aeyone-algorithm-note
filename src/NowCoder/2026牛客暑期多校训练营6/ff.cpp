#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned int;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

// #define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

#ifdef LOCAL 
    int test = 1;
#else
    int test = 0;
#endif

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector<int> ne(n + 1);
    for (int i = 2, j = 0; i <= n; i ++) { 
        while (j && s[i] != s[j + 1]) {
            j = ne[j];
        }
        if (s[i] == s[j + 1]) {
            j ++;
        }
        ne[i] = j;
    }
    int m = 26;
    vector<int> a(m);
    for (int i = 2; i <= n; i ++) { // s[ne[i] + 1] < s[ne[i] + i]
        a[s[ne[i] + i] - 'a'] |= (1 << (s[ne[i] + 1] - 'a'));
    }
    vector<u32> dp(1 << m);
    dp[0] = 1;
    for (int mask = 0; mask < 1 << m; mask ++) {
        int S = 0;
        for (int i = 0; i < m; i ++) {
            if (mask >> i & 1) {
                S |= a[i];
            }
        }
        for (int i = 0; i < m; i ++) {
            if (!(mask >> i & 1) && !(S >> i & 1)) {
                dp[mask | (1 << i)] += dp[mask];
            }
        }
    }
    cout << dp.back() << '\n';
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