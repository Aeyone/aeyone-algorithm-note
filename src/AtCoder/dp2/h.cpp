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
	int n, W, C;
	cin >> n >> W >> C;
	vector a(51, vector<array<int, 2>>{});
	for (int i = 0; i < n; i ++) {
		int w, v, c;
		cin >> w >> v >> c;
		a[c].push_back({w, v});
	}
	vector dp(2, vector(C + 1, vector<int>(W + 1, -INF)));
	dp[0][0][0] = 0;
	for (int c = 1; c <= 50; c ++) {
		vector f(2, vector<int>(W + 1, -INF));
		f[1][0] = 0;
		int tot = a[c].size();
		for (int p = 0; p < tot; p ++) {
			auto [w, v] = a[c][p];

			for (int j = w; j <= W; j ++) {
				f[p & 1][j] = max(f[p & 1][j], f[p - 1 & 1][j]);
				f[p & 1][j] = max(f[p & 1][j], f[p - 1 & 1][j - w] + v);
			}
		}
		dp[c & 1] = dp[c - 1 & 1];
		// for (int i = 0; i < C; i ++) {
		// 	for (int j = 0; j <= W; j ++) {
		// 		dp[c & 1][i + 1][j] = max(dp[c & 1][i][j], )
		// 	}
		// }
	}
	// int ans = 0;
	// for (int c = 1; c <= 50; c ++) {
	// 	for (int i = 0; i <= C; i ++) {
	// 		for (int j = 0; j <= W; j ++) {
	// 			ans = max(ans, dp[c][i][j]);
	// 		}
	// 	}
	// }
	// cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}