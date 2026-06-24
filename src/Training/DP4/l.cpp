#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

#ifdef LOCAL 
    int test = 1;
#else
    int test = 0;
#endif

const int MOD = 998244353;
const int N = 2000 + 10;
double dp[N][N][2][2];

void solve() {
    int n, h;
    cin >> n >> h;
    double p;
    cin >> p;
    vector<int> a(n + 2), toL(n + 1), toR(n + 1);
    a[0] = -INFLL, a[n + 1] = INFLL;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 1; i <= n; i ++) {
        int j = i;
        while (j <= n && a[j + 1] - a[j] < h) j ++;
        toL[i] = j;
        j = i;
        while (j >= 1 && a[j] - a[j - 1] < h) j --;
        toR[i] = j;
    }

    // vector dp(n + 2, vector(n + 2, vector(2, vector<double>(2))));
    // dp[l][r][x][y]代表区间l~r的树全部倒下的期望长度，l左边的树状态为x，r右边的树状态为y
    // 0表示向右倒下，1表示向左倒下

    auto dfs = [&](auto &&self, int l, int r, int x, int y)-> double {
        if (l > r) return 0;
        if (dp[l][r][x][y] != 0) return dp[l][r][x][y];

        int minL = min(h, a[l] - a[l - 1] - (x ? 0 : h));
        int minR = min(h, a[r + 1] - a[r] - (y ? h : 0));
        
        int L = min(r, toL[l]), R = max(l, toR[r]);
        int lenL = (a[L] + h - a[l]), lenR = (a[r] - a[R] + h);
        if (L == r) lenL = a[L] - a[l] + minR;
        if (R == l) lenR = a[r] - a[R] + minL;

        dp[l][r][x][y] += 0.5 * p * (self(self, l + 1, r, 1, y) + minL);
        dp[l][r][x][y] += 0.5 * (1.0 - p) * (self(self, L + 1, r, 0, y) + lenL);

        dp[l][r][x][y] += 0.5 * p * (self(self, l, R - 1, x, 1) + lenR);
        dp[l][r][x][y] += 0.5 * (1.0 - p) * (self(self, l, r - 1, x, 0) + minR);

        return dp[l][r][x][y];
    };
    cout << dfs(dfs, 1, n, 1, 0) << '\n';
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