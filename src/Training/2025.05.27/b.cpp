#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<array<int, 2>> d(n);
	for(int i = 0; i < n; i ++)
		cin >> d[i][0] >> d[i][1];

	vector<int> vis(1010, 0);
	for(auto &[a, b] : d){
		for(int i = min(a, b); i <= max(a, b); i ++)
			vis[i] ++;
	}

	vector<int> l;
	for(int i = 0; i <= 1000; i ++)
		// cout << vis[i] <<'\n';
		if(vis[i] == n)
			l.push_back(i);

	int ans = 1e9;
	for(auto e : l)
		ans = min(ans, abs(e - x));
		// cout << e << '\n';

	if(ans == 1e9)
		cout << -1 << '\n';
	else
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