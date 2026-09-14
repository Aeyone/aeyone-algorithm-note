#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve () {
	int n, m;
	cin >> n >> m;
	int la = 0, ans = 0;
	for (int i = 0; i < n; i ++) {
		int sum = 0;
		for (int j = 0; j < m; j ++) {
			int x;
			cin >> x;
			sum += x;
		}
		if (sum < la) ans ++;
		la = sum;
	}
	cout << ans << '\n';
}

signed main () {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}