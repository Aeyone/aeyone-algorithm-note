#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	vector<vector<int>> dp(n, vector<int>(n + 1));
	dp[0][0] = 1;
	for(int i = 1; i < n; i ++){
		dp[i][0] = 1;
		for(int j = 0; j < i; j ++){
			if(a[i] >= a[j]){
				for(int k = 0; k <= n; k ++)
					dp[i][k] += dp[j][k];
			}else{
				dp[i][a[j]] += dp[j][0];
				for(int k = 1; k <= a[i]; k ++)
					dp[i][k] += dp[j][k];
			}
		}
	}
	i64 ans = 1;
	for(int i = 0; i < n; i ++){
		cout << "a[i] = " << a[i] << " | ";
		for(int j = 0; j <= n; j ++){
			cout << dp[i][j] << ' ';
			ans = (ans + dp[i][j]) % mod;
		}
		cout << '\n';
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}