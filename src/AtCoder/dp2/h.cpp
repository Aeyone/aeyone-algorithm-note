#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

/*	
*	dp[i][j][k]代表考虑前i种颜色，总共选了j种颜色，总重量为k的最大价值
*	考虑该颜色为第一次放入背包，dp[x][i][j][k] <- dp[x - 1][i - 1][j - 1][k - w] + v
*	考虑该颜色不是第一次放入背包，dp[x][i][j][k] <- dp[x - 1][i][j][k - w] + v
*/ 

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
		dp[1].assign(C + 1, vector<int>(W + 1, -INF));
		for (auto [w, v] : a[c]) {
			for (int j = C; j >= 0; j --) {
				for (int k = W; k >= 0; k --) {
					if (k >= w) {
						dp[1][j][k] = max(dp[1][j][k], dp[1][j][k - w] + v);
						if (j >= 1) {
							dp[1][j][k] = max(dp[1][j][k], dp[0][j - 1][k - w] + v);
						}
					}
				}
			}
		}
		for (int j = 0; j <= C; j ++) {
			for (int k = 0; k <= W; k ++) {
				dp[0][j][k] = max(dp[0][j][k], dp[1][j][k]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= C; i ++) {
		for (int j = 0; j <= W; j ++) {
			ans = max(ans, dp[0][i][j]);
		}
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