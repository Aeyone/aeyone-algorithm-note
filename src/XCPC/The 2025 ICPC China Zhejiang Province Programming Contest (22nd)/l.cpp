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
    vector<int> a(n), in(n), cy(n, 1);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i] --;
        in[a[i]] ++;
    }
    queue<int> q;
    for (int i = 0; i < n; i ++) if (!in[i]) {
        q.push(i);
    }

    vector<array<int, 2>> dp(n, {0, 1});
    while (q.size()) {
        auto u = q.front();
        q.pop();

        cy[u] = 0;
        // cerr << "u = " << u + 1 << '\n';

        dp[a[u]][0] += max(dp[u][0], dp[u][1]);
        dp[a[u]][1] += dp[u][0];

        if (-- in[a[u]] == 0) {
            q.push(a[u]);
        }
    }
    auto dp1 = dp; // dp1为考虑环上第一个选的点为1的情况
    int ans = 0;
    for (int i = 0; i < n; i ++) if (cy[i]) {
        cy[i] = false;
        if (a[i] == i) {
            ans += dp[i][0];
            continue;
        }
        dp[a[i]][0] += dp[i][0];
        dp[a[i]][1] += dp[i][0];

        dp1[a[i]][0] += max(dp1[i][0], dp1[i][1]);
        dp1[a[i]][1] += dp1[i][0];
        int x = a[i];
        cy[x] = false;
        while (a[x] != i) {
            dp1[a[x]][0] += max(dp1[x][0], dp1[x][1]);
            dp1[a[x]][1] += dp1[x][0];

            dp[a[x]][0] += max(dp[x][0], dp[x][1]);
            dp[a[x]][1] += dp[x][0];
            x = a[x];
            cy[x] = false;
        }
        ans += max({dp[x][0], dp[x][1], dp1[x][0]});
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t --) {
        solve();
    }
}