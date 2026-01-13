#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> x(n), t(n);
	for(int i = 0; i < n; i ++)
		cin >> x[i];
	for(int i = 0; i < n; i ++)
		cin >> t[i];

	int l = 1e9, r = -1e9;
	for(int i = 0; i < n; i ++){
		l = min(l, x[i] - t[i]);
		r = max(r, x[i] + t[i]);
	}
	printf("%.8lf\n", double(l + r) / 2);
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}