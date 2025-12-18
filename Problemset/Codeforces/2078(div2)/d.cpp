#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<pair<char, int>> a(n), b(n);
	for(int i = 0; i < n; i ++){
		char c1, c2;
		int x1, x2;
		cin >> c1 >> x1 >> c2 >> x2;
		a[i] = {c1, x1};
		b[i] = {c2, x2};
	}
	vector<array<i64, 2>> dp(n + 1), f(n + 1);
	f[n] = {1, 1};
	for(int i = n - 1; i >= 0; i --){
		i64 mx = max(f[i + 1][0], f[i + 1][1]);
		f[i][0] = (a[i].first == 'x' ? f[i + 1][0] + mx * (a[i].second - 1) : f[i + 1][0]);
		f[i][1] = (b[i].first == 'x' ? f[i + 1][1] + mx * (b[i].second - 1): f[i + 1][1]);
	}
	dp[0] = {1, 1};
	for(int i = 0; i < n; i ++){
		i64 cnt = 0;
		if(a[i].first == 'x')
			cnt += dp[i][0] * (a[i].second - 1);
		elses
			cnt += a[i].second;

		if(b[i].first == 'x')
			cnt += dp[i][1] * (b[i].second - 1);
		else
			cnt += b[i].second;

		int x = (f[i + 1][1] > f[i + 1][0]);

		dp[i + 1][x] = dp[i][x] + cnt;
		dp[i + 1][!x] = dp[i][!x];
	}
	for(int i = 0; i <= n; i ++)
		cout << f[i][0] << ' ' << f[i][1] << '\n';
	cout << dp[n][0] + dp[n][1] << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}