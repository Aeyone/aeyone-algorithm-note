#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for(int i = 0; i < n; i ++){
		int x, y;
		cin >> x >> y;
		if(!i){
			ans += 4 * m;
			continue;
		}
		ans += 4 * m - 2 * ((m - x) + (m - y));
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}