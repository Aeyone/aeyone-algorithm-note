#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(m);
	for(int i = 0; i < m; i ++){
		int x, y;
		cin >> x >> y;
		a[i] = {y, x};
	}
	sort(a.begin(), a.end(), greater<pair<int, int>>{});
	int ans = 0;
	for(auto [x, y] : a){
		if(n - y >= 0)
			ans += x * y, n -= y;
		else{
			ans += x * n;
			break;
		}
	}
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