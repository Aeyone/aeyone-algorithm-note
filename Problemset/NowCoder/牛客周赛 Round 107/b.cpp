#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(2 * n + 1), la(n + 1);
	int ans = 0;
	for(int i = 1; i <= 2 * n; i ++){
		cin >> a[i];
		if(!la[a[i]])
			la[a[i]] = i;
		else
			ans = max(ans, i - la[a[i]] + 1);
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}