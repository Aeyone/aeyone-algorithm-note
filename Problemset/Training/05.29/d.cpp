#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < n; i ++){
		if(a[i] >= 0 || !m)
			break;
		ans -= a[i];
		m --;
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