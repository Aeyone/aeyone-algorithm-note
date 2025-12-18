#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 2);
	int ans = 0;
	for(int i = 0; i < q; i ++){
		int u;
		cin >> u;
		ans += (!(a[u] & 1) && !(a[u - 1] & 1) && !(a[u + 1] & 1));
		ans -= ((a[u] & 1) && !(a[u - 1] & 1) && !(a[u + 1] & 1));

		ans += ((a[u] & 1) && (a[u - 1] & 1) && (a[u + 1] & 1));
		ans -= (!(a[u] & 1) && (a[u - 1] & 1) && (a[u + 1] & 1));

		a[u] ++;
		cout << ans << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}