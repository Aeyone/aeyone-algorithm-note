#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, s;
	cin >> n >> s;
	int ans = 0;
	for(int i = 0; i < n; i ++){
		int dx, dy, x, y;
		cin >> dx >> dy >> x >> y;
		if(x == y && dx * dy > 0)
			ans ++;
		else if(x + y == s && dx * dy < 0)
			ans ++;
	}
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