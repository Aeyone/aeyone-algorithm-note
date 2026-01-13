#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	for(int i = 0; i < n; i ++)
		cin >> b[i];

	int ca = 0, cb = 0, c1 = 0, c2 = 0;
	for(int i = 0; i < n; i ++){
		if(a[i] > b[i])
			ca += a[i];
		if(b[i] > a[i])
			cb += b[i];
		if(a[i] == b[i]){
			if(a[i] < 0)
				c1 ++;
			if(a[i] > 0)
				c2 ++;
		}
	}
	int mn = min(ca, cb), mx = max(ca, cb);
	int d = mx - mn;
	int ans = 0;

	mn = min(mx, mn + c2);//最高加到多少
	c2 = max(c2 - d, 0);//消耗多少1
	d = mx - mn;

	mx = min(mn, mx - c1);
	c1 = max(c1 - d, 0);
	if(c2 >= c1)
		ans = mn + (c2 - c1) / 2;//加是下取整
	else
		ans = mn - (c1 - c2 + 1) / 2;//减是上取整
	cout << ans << '\n';
	// cout << min(ca, cb) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}