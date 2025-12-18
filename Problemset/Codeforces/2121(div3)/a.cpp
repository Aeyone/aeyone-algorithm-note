#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, s;
	cin >> n >> s;
	vector<int> x(n);
	int mn = 1e9, mx = 0;
	for(int i = 0; i < n; i ++){
		cin >> x[i];
		mn = min(mn, x[i]);
		mx = max(mx, x[i]);
	}
	int ans = 0;
	if(mn < s && mx > s)
		ans = min(s - mn, mx - s) + mx - mn;
	else
		ans = max(abs(s - mn), abs(s - mx));
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