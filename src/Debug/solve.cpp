#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

template<typename T> bool cmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
template<typename T> bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector dp(n + 2, vector<pair<int, string>>(n + 2));

    for (int len = 1; len <= n; len ++) {
        for (int l = 1, r = l + len - 1; r <= n; l ++, r ++) {
            dp[l][r] = {0, s.substr(l, len)};
            for (int i = l; i + 2 <= r; i ++) {
                if (s.substr(i, 3) == "iwi") {
                    string str = dp[l][i - 1].second + dp[i + 3][r].second;
                    int cnt = 1, idx = -1;
                    for (int j = 0; j + 2 < str.size(); j ++) {
                        if (str.substr(j, 3) == "iwi") {
                            idx = j;
                        }
                    }
                    if (idx != -1) {
                        cnt ++;
                        str = str.substr(0, idx) + str.substr(idx + 3, str.size() - idx - 3);
                    }
                    cmax(dp[l][r], {cnt + dp[l][i - 1].first + dp[i + 3][r].first, str});
                }
            }
        }
    }
    cout << dp[1][n].first << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int _ = 1;
    while (_ --) {
        solve();
    }
}