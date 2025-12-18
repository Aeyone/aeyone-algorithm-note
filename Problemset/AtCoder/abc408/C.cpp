#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<array<int, 2>> d(m);
	for(int i = 0; i < m; i ++)
		cin >> d[i][0] >> d[i][1];

	vector<int> dif(n + 1, 0);
	for(auto &[a, b] : d){
		dif[a] ++;
		if(b != n)
			dif[b + 1] --;
	}
	vector<int> res(n + 1, 0);
	for(int i = 1; i <= n; i ++)
		res[i] = res[i - 1] + dif[i];

	int ans = 2e9;
	for(int i = 1; i <= n; i ++)
		ans = min(ans, res[i]);
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