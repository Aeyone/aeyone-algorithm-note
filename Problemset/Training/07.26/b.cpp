#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	for(auto &e : a)
		cin >> e, mp[e] ++;
	int mex = 0;
	while(mp.find(mex) != mp.end())
		mex ++;
	
	if(mex == 0){
		cout << 0 << '\n';
		return;
	}
	vector<int> dp(mex, inf);
	dp[0] = 0;
	for(int i = 1; i < mex; i ++){
		for(int j = 0; j < i; j ++)
			dp[i] = min(dp[i], i * mp[j] + dp[j]);
	}

	i64 ans = inf;
	for(int i = 0; i < mex; i ++)
		ans = min(ans, (i64)mex * (mp[i] - 1) + dp[i]);

	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}