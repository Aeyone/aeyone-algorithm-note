#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;
const int N = 4e6 + 200;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> t(N + 1), s(N + 1), c(N + 1);
    int max = 0;
    for (int i = 0; i < n; i ++) {
        int e;
        cin >> e;
        t[e + 1] ++;
        max = std::max(max, e + 1);
    }
    for (int i = 1; i <= N; i ++) {
        c[i] = c[i - 1] + t[i];
        s[i] = s[i - 1] + i * t[i];
    }
    vector<int> dp(N + 1);
    deque<int> q;
    q.push_back(0);

    auto up = [&](int i, int j)-> int {
        return (dp[i] + s[i]) - (dp[j] + s[j]);
    };

    auto down = [&](int i, int j)-> int {
        return c[i] - c[j];
    };

    for (int i = 1; i <= N; i ++) {
        int k = i - m;
        if (k >= 0) {
            int siz = q.size();
            while (q.size() >= 2 && (i128)up(q[siz - 2], q[siz - 1]) * down(q[siz - 1], k) >= (i128)up(q[siz - 1], k) * down(q[siz - 2], q[siz - 1])) {
                siz --;
                q.pop_back();
            }
            q.push_back(k);
        }        
        while (q.size() >= 2 && (i128)i * down(q[0], q[1]) <= up(q[0], q[1])) {
            q.pop_front();
        }
        int j = q[0];
        dp[i] = dp[j] + i * (c[i] - c[j]) - (s[i] - s[j]);
    }
    int ans = INFLL;
    for (int i = max; i <= max + m; i ++) ans = std::min(ans, dp[i]);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t --) {
        solve();
    }
}