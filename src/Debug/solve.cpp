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
    int n, m;
    cin >> n >> m;
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
    }
    set<char> st {'k', 'n', 'a', 'r', 'e'};
    string let = "knare";
    vector<vector<pair<int, int>>> val(n + 1, vector<pair<int, int>>(5));
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 5; j ++) {
            int cur = j, tot = 0, cnt = 0;
            for (int k = 0; k < m; k ++) {
                if (s[i][k] == let[(cur + 1) % 5]) {
                    cur = (cur + 1) % 5;
                    cnt += cur == 0;
                } else if (st.find(s[i][k]) != st.end()) {
                    tot ++;
                }
            }
            if (cnt > 0) {
                tot -= j;
            }
            val[i][j] = {5 * cnt - (tot + cur), cur};
        }
    }

    vector<vector<int>> dp(n + 1, vector<int> (5, -INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 5; j ++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][val[i][j].second] = max(dp[i][val[i][j].second], dp[i - 1][j] + val[i][j].first);
        }
    }
    int mx = 0;
    for (int i = 0; i < 5; i ++) {
        mx = max(mx, dp[n][i]);
    }
    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int _ = 1;
    while (_ --) {
        solve();
    }
}