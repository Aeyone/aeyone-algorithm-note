#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	vector<i64> dp(n + 1);
	for(int i = 1; i <= n; i ++){
		vector<int> p;
		for(int j = 2; j <= a[i] / j; j ++){
			if(a[i] % j == 0 && j <= n){
				p.push_back(j);
				int k = a[i] / j;
				if(k <= n && k != j)
					p.push_back(k);
			}
		}
		if(a[i] <= n)
			p.push_back(a[i]);
		sort(p.begin(), p.end(), greater<int>());
		for(auto e : p){
			if(a[i] % e == 0)
				dp[e] = (dp[e - 1] + dp[e]) % mod;
		}
		dp[1] = i;
		// for(int j = 1; j <= m; j ++)
		// 	cout << dp[j] << " ";
		// cout << '\n';
	}
	i64 ans = 0;
	for(int i = 1; i <= n; i ++)
		ans = (ans + dp[i]) % mod;

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