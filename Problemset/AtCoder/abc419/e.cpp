#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m, L;
	cin >> n >> m >> L;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	vector<vector<int>> dp(L + 1, vector<int>(m, 2e9));
	dp[0][0] = 0;
	for(int i = 1; i <= L; i ++){
		for(int j = 0; j < m; j ++){
			int cost = 0;//i组变为 %m = j 的贡献
			for(int k = i; k <= n; k += L)
				cost += (j - a[k] + m) % m;

			for(int k = 0; k < m; k ++)
				dp[i][(j + k) % m] = min(dp[i][(j + k) % m], dp[i - 1][k] + cost);
		}
	}
	cout << dp[L][0] << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}