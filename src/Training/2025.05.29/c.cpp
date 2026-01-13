#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	int ans[2] = {0, n - 1};

	for(int i = 1; i < n; i ++){
		if(abs(a[i] - a[i - 1]) < abs(a[ans[0]] - a[ans[1]]))
			ans[0] = i - 1, ans[1] = i;
	}

	cout << ans[0] + 1 << " "  << ans[1] + 1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}