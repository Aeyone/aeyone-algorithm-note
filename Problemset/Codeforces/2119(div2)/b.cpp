#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	i64 px, py, qx, qy;
	cin >> px >> py >> qx >> qy;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	double d = sqrt((qx - px) * (qx - px) + (qy - py) * (qy - py));
	int l = a[0], r = a[0];
	for(int i = 1; i < n; i ++){
		if(l - a[i] >= 0)
			l -= a[i];
		else
			l = max(0, a[i] - r);
		r += a[i];
	}
	if(d >= l && d <= r)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}