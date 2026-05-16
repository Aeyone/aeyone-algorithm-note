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
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	const int N = 3000;

	// dp[i][j] 为考虑前i个建筑 第一座高度减去第二座高度为j 的第一座塔高度的最大值
	vector<vector<int>> dp(2, vector<int>(2 * N + 1, -INF));
	dp[0][N] = 0;

	for (int i = 1; i <= n; i ++) {
		for (int j = 2 * N; j >= 0; j --) {
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (j - a[i] >= 0) dp[i & 1][j] = max(dp[i & 1][j], dp[i - 1 & 1][j - a[i]] + a[i]);
			if (j + a[i] <= 2 * N) dp[i & 1][j] = max(dp[i & 1][j], dp[i - 1 & 1][j + a[i]]);
		}
	}

	if (dp[n & 1][N] <= 0) {
		cout << "Impossible" << '\n';
	} else {
		cout << dp[n & 1][N] << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}