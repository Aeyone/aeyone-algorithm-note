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
	vector<int> w(n), v(n);
	for (int i = 0; i < n; i ++) {
		cin >> w[i] >> v[i];
	}
	vector<vector<int>> dp(2, vector<int>(1e5 + 1, INF));
	dp[1][0] = 0;
	for (int i = 0; i < n; i ++) {
		dp[i & 1] = dp[~i & 1];
		for (int j = 1e5; j - v[i] >= 0; j --) {
			if (dp[~i & 1][j - v[i]] + w[i] <= m) {
				dp[i & 1][j] = min(dp[i & 1][j], dp[~i & 1][j - v[i]] + w[i]);
			}
		}
	}
	i64 ans = 0;
	for (int i = 0; i <= 1e5; i ++) {
		if (dp[(n - 1) & 1][i] <= m) {
			ans = i;
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