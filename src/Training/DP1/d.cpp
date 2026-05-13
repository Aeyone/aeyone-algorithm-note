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
	i64 t;
	cin >> t;
	i64 n1, n2, s1, s2;
	cin >> n1 >> n2;
	cin >> s1 >> s2;
	vector<i64> c(5);
	for (int i = 0; i <= 4; i ++) {
		c[i] = max(0ll, (t - i * s2) / s1);
	}

	vector<vector<i64>> dp(n1 + 1, vector<i64>(n2 + 1, INFLL)); // dp[i][j]代表第一种i个，第二种j个的最小购物袋数量
	dp[0][0] = 0;

	for (int i = 0; i <= n1; i ++) {
		for (int j = 0; j <= n2; j ++) {
			for (int k = 0; k <= 4; k ++) if (j - k >= 0 && s2 * k <= t) {
				dp[i][j] = min(dp[i][j], dp[max(0ll, i - c[k])][j - k] + 1);
			}
		}
	}

	cout << dp[n1][n2] << '\n';

}

signed main() {
	freopen("shopping.in", "r", stdin), freopen("shopping.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}