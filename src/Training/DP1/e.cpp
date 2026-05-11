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
	vector<i64> w(n), v(n);
	for (int i = 0; i < n; i ++) {
		cin >> w[i] >> v[i];
	}
	const int N = 500;
	vector<vector<i64>> dp(n + 1, vector<i64>(N + 1)); // dp[i][j][k]代表从前i个物品中选了j个，并且重量总和减去j*w[1]为k时的最大价值

	for (int i = 0; i < n; i ++) {
		for (int j = n; j >= 1; j --) {
			for (int k = N; k >= w[i] - w[0]; k --) {
				if (1ll * j * w[0] + k > m) continue;
				dp[j][k] = max(dp[j][k], dp[j - 1][k - (w[i] - w[0])] + v[i]);
			}
		}
	}

	i64 ans = 0;
	for (int i = 0; i <= n; i ++) {
		ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
	}
	cout << ans << '\n';

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}