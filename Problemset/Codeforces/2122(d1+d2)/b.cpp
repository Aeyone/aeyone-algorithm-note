#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	i64 c0 = 0, need = 0;
	for(int i = 0; i < n; i ++){
		if(a[i] > c[i])
			c0 += (a[i] - c[i]), a[i] = c[i];
		if(a[i] < c[i])
			need += (c[i] - a[i]);
	}
	i64 ans = c0;
	c0 -= need;
	for(int i = 0; i < n; i ++){
		if(b[i] > d[i])
			ans += (b[i] - d[i] + a[i]);
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