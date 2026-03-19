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
*	dp[i][j]为考虑前i个水瓶，总容量为j的空间，容器数量为k个，最少需要装多少水
*	考虑作为容器 dp[i][j][k] <- dp[i-1][j-(b[i]-a[i])][k-1]
*	不考虑作为容器 dp[i][j][k] <- dp[i-1][j][k] + a[i]
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	int sum = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> b[i];
		sum += b[i];
	}

	vector dp(2, vector(sum + 1, vector<int>(n + 1, INF)));
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i ++) {
		dp[i & 1].assign(sum + 1, vector<int>(n + 1, INF));
		for (int j = 0; j <= sum; j ++) {
			for (int k = 0; k <= n; k ++) {
				dp[i & 1][j][k] = min(dp[i & 1][j][k], dp[~i & 1][j][k] + a[i]);
				if (j >= b[i] - a[i] && k > 0) {
					dp[i & 1][j][k] = min(dp[i & 1][j][k], dp[~i & 1][j - (b[i] - a[i])][k - 1]);
				}
			}
		}
	}
	array<int, 2> ans;
	for (int k = 0; k <= n; k ++) {
		for (int j = 0; j <= sum; j ++) {
			if (dp[n & 1][j][k] <= j) {
				ans = min(ans, {k, dp[n & 1][j][k]});
			}
		}
	}
	cout << ans[0] << ' ' << ans[1] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}