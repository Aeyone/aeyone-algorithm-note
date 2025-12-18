#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	i64 sum = 0;
	vector<i64> b(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> b[i], sum += b[i];

	vector<vector<array<int, 2>>> g(n + 1);
	for(int i = 1; i <= m; i ++){
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
	}

	auto check = [&](i64 x) -> bool{
		vector<i64> dp(n + 1, -1e16);
		dp[1] = min((i64)b[1], x);
		
		for(int u = 1; u < n; u ++){
			for(auto &[j, w] : g[u]){
				if(dp[u] >= w)
					dp[j] = max(dp[j], dp[u] + b[j]);
				dp[j] = min(dp[j], x);
			}
		}
		return (dp[n] >= 0);
	};

	i64 l = 0, r = sum, ans = -1;
	while(l <= r){
		i64 mid = (l + r) >> 1;
		if(check(mid))
			r = mid - 1, ans = mid;
		else
			l = mid + 1;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _;
	cin >> _;
	while (_ --)
		solve();
}