#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 1e5 + 10;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), cnt(N);
	for (int i = 0; i < n; i ++)
		cin >> a[i], cnt[a[i]] ++;

	vector<i64> dp(N);
	dp[1] = cnt[1] * 1;
	dp[2] = cnt[2] * 2;
	dp[3] = cnt[3] * 3 + dp[1];
	i64 ans = 0;
	for (int i = 1; i <= 3; i ++) {
		ans = max(ans, dp[i]);
	}

	for (int i = 4; i < N; i ++) {
		dp[i] = max(dp[i - 2], dp[i - 3]) + (i64)i * cnt[i];
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}

signed main() {
	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
//	int _;
//	cin >> _;
//	while (_ --)
	solve();
}