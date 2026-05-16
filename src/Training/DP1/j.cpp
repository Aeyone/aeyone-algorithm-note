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
	vector<vector<i64>> a(n + 1, vector<i64>(m + 1)), dp(n + 1, vector<i64>(m + 1, -INFLL));
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> a[i][j];
		}
	}

	dp[1][0] = 0;
	for (int i = 1; i <= m; i ++) {
		vector<i64> pre(n + 1, -INFLL), suf(n + 2, -INFLL);
		for (int j = 1; j <= n; j ++) {
			pre[j] = max(pre[j - 1], dp[j][i - 1]) + a[j][i];
		}
		for (int j = n; j >= 1; j --) {
			suf[j] = max(suf[j + 1], dp[j][i - 1]) + a[j][i];
			dp[j][i] = max(pre[j], suf[j]);
		}
	}

	cout << dp[n][m] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}