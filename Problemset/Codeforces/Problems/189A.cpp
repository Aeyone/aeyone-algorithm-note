#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<int> dp(n + 1, 0);
	map<int, bool> m;
	m[0] = m[a] = m[b] = m[c] = true;
	for(int i = 1; i <= n; i ++){
		for(auto [e, _] : m)
			if(i - e >= 0 && m.find(i - e) != m.end())
				dp[i] = max(dp[i], dp[i - e] + 1), m[i] = true;
	}
	// for(int i = 1; i <= n; i ++)
	// 	cout << dp[i] << " ";
	// cout << '\n';
	cout << dp[n] <<'\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data /data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	// int _;
	// cin >> _;
	// while (_ --)
		solve();
}