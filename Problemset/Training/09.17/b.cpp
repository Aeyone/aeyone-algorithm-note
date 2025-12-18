#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a)
		cin >> e;

	int dp[2] = {}, back[2] = {};
	back[1] = (a[0] == 0), back[0] = 1;
	for(int i = 1; i < n; i ++){
		dp[0] = back[1];
		dp[1] = 0;
		if(a[i] == a[i - 1])
			dp[1] = (dp[1] + back[1]) % mod;
		if((i == 1 && a[i] == 1) || (i > 1 && a[i] == a[i - 2] + 1))
			dp[1] = (dp[1] + back[0]) % mod;
		back[0] = dp[0], back[1] = dp[1];
	}
	cout << (back[0] + back[1]) % mod << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}