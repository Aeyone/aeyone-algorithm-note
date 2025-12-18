#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int l, d, v, g, r;
	cin >> l >> d >> v >> g >> r;
	double t1 = (double)d / v;
	double tmp = t1 - (int)(t1 / (g + r)) * (g + r);
	
	if(tmp < (r + g) && tmp >= g)
		t1 += (g + r -tmp);

	t1 += (double)(l - d) / v;
	printf("%.7f\n", t1);
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}