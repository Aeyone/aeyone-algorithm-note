#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	int ans = 0;
	for(int i = 0; i < n; i ++){
		int a, b;
		cin >> a >> b;
		ans += (a <= l && b >= r);
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