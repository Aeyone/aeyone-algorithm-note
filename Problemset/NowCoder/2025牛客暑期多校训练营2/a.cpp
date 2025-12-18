#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	vector<array<int, 2>> b;
	int sign = a[0], d = 0;
	for(int i = 0; i < n; i ++){
		if(a[i] == -1){
			if(d)
				b.push_back({sign, d});
			sign = -1, d = 0;
			b.push_back({-1, 1});
			continue;
		}
		if(a[i] == sign)
			d ++;
		else{
			if(d)
				b.push_back({sign, d});
			sign = a[i], d = 1;
		}
	}
	if(d)
		b.push_back({sign, d});
	n = b.size();
	vector<array<i64, 2>> dp(n);
	i64 cnt = 0, ans = 0;
	if(b[0][0] == 1)
		dp[0][1] = 1, ans = 1;
	if(b[0][0] == 0)
		dp[0][0] = 1;
	if(b[0][0] == -1)
		dp[0][0] = dp[0][1] = 1;

	for(int i = 1; i < n; i ++){
		if(b[i][0] == 0)
			dp[i][0] += dp[i - 1][1], dp[i][1] = 0;
		
		if(b[i][0] == 1){
			dp[i][1] += dp[i - 1][0], dp[i][0] = 0;
			cnt += dp[i - 1][0];
		}
		if(b[i][0] == -1){
			ans = ((ans + cnt) * 2) % mod;
			cnt = dp[i - 1][0];
			dp[i][0] = dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]);
		}
		cout << ans << ' ' << cnt << '\n';
	}
	// cout << (ans + cnt) % mod << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}