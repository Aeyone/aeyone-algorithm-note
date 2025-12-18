#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(2 * n + 1), l(n + 1), r(n + 1);
	for(int i = 1; i <= 2 * n; i ++){
		cin >> a[i];
		if(!l[a[i]])
			l[a[i]] = i;
		else
			r[a[i]] = i;
	}
	vector<i64> s(2 * n + 1), sum(n + 1), dp(2 * n + 1);//dp[i]表示到位置i时能获得的最大分数
	for(int i = 1; i <= 2 * n; i ++)
		s[i] = s[i - 1] + a[i];

	for(int i = 1; i <= n; i ++)
		sum[i] = s[r[i]] - s[l[i] - 1];

	for(int i = 1; i <= 2 * n; i ++){
		if(i == l[a[i]]){
			dp[i] = dp[i - 1];
			continue;
		}
		dp[i] = max(dp[i - 1], dp[l[a[i]] - 1] + sum[a[i]]);
	}
	cout << dp[2 * n] << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}