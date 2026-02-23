#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

vector<int> minp, p;
 
void sieve(int n) {
    minp.assign(n + 1, 0);
    p.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            p.push_back(i);
        }
        for (auto e : p) {
            if (1ll * i * e > n) {
                break;
            }
            minp[i * e] = e;
            if (e == minp[i]) {
                break;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<vector<int>> ps(n + 1);
    int m = 5e5 + 10;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        int x = a[i];
        for (auto e : p) {
            if (x % e == 0) {
                ps[i].push_back(e);
            }
            while (x % e == 0) {
                x /= e;
            }
        }
        if (x > 1) {
            ps[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }

    vector<set<array<int, 2>>> dp(m);

    auto check = [&](int &mx, int idx, int c)->void{
        if (dp[idx].size() == 0) {
            return;
        }
        auto [len1, c1] = *(--dp[idx].end());
        if (dp[idx].size() == 2) {
            auto [len2, c2] = *dp[idx].begin();
            mx = max(mx, c1 == c ? len2 : len1);
        } else {
            mx = max(mx, c1 == c ? 0 : len1);
        }
    };

    auto update = [&](int mx, int idx, int c)->void{
        if (dp[idx].size() == 2) {
            auto [len1, c1] = *(--dp[idx].end());
            auto [len2, c2] = *dp[idx].begin();
            if (c != c1 && c != c2) {
                dp[idx].insert({mx, c});
                dp[idx].erase(dp[idx].begin());
            } else if (c == c1) {
                if (mx > len1) {
                    dp[idx].erase(*(--dp[idx].end()));
                    dp[idx].insert({mx, c});
                }
            } else if (c == c2) {
                if (mx > len2) {
                    dp[idx].erase(dp[idx].begin());
                    dp[idx].insert({mx, c});
                }
            }
        } else {
            dp[idx].insert({mx, c});
        }
    };

    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (auto p : ps[i]) {
            check(mx, p, b[i]);
        }
        mx ++;
        for (auto p : ps[i]) {
            update(mx, p, b[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i ++) {
        if (dp[i].size() > 0) {
            auto [len1, c1] = *(--dp[i].end());
            ans = max(ans, len1);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    sieve(1e3);
//    cin >> _;
    while (_ --) {
        solve();
    }
}