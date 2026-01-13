#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> ne(n + 1, n + 1);
	for(int i = 0; i < m; i ++){
		int x, y;
		cin >> x >> y;
		if(x > y)
			swap(x, y);

		ne[x] = min(ne[x], y);
	}
	for(int i = n - 1; i >= 1; i --)
		ne[i] = min(ne[i], ne[i + 1]);
	
	i64 ans = 0;
	for(int i = 1; i <= n; i ++)
		ans += (ne[i] - i);
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