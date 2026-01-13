#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, b;
	cin >> n >> b;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	int ans = b;
	for(int i = 0; i < n; i ++){
		for(int j = i + 1; j < n; j ++){
			if(a[i] >= a[j])
				continue;
			ans = max(ans, (a[j] - a[i]) * (b / a[i]) + b);
		}
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