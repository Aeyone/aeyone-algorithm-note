#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	vector<i64> dp(n + 1, -1e16);
	// for(int i = 0; i <= n; i ++)
	// 	dp[i][0] = 0;  
	dp[0] = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = i; j >= 1; j --){
			if(dp[j - 1] + a[i] >= 0)
				dp[j] = max(dp[j], dp[j - 1] + a[i]);
		}
	}
	int ans = 0;
	// for(int i = 1; i <= n; i ++){
	// 	if(a[i] > 0)
	// 		cout << " ";
	// 	cout << a[i] << ": ";
	// 	for(int j = 0; j <= i; j ++)
	// 		cout << dp[i][j] << " ";
	// 	cout << '\n';
	// }
	for(int i = 1; i <= n; i ++)
		if(dp[i] >= 0)
			ans = i;
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}