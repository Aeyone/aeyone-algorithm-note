#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	vector<vector<int>> to(n + 1);//记录每个点可以由哪些点而来
	for(int i = 0; i < n; i ++){
		if(a[i] + i + 1 <= n){
			int x = a[i] + i + 1;
			to[x].push_back(i);
		}
	}
	vector<int> dp(n + 1);
	for(int i = 1; i <= n; i ++){
		dp[i] = dp[i - 1] + 1;
		for(auto u : to[i])//复杂度依然是o(n)的，最多有n-1条边
			dp[i] = min(dp[i], dp[u]);
	}
	cout << dp[n] << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}