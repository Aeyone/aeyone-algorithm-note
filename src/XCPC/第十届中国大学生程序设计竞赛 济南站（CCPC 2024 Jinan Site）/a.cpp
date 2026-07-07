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
    int test = 0;
#endif

const int MOD = 998244353;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n);
    for (int i = 0; i < n; i ++) {
        cin >> g[i];
    }
    map<string, int> mp;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            string s = g[i].substr(j * k, k);
            mp[s] ++;
        }
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            string s = g[i].substr(j * k, k);
            if (mp[s] == 1) {
                x = i + 1, y = j + 1;
            }
        }
    }
    cout << x << ' ' << y << '\n';

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