#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f

const int MOD = 998244353;

void solve () {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	int ans = 1;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if ((i & 1) && a[i] == (i - 1) / 2) {
			ans = (ans * 2) % MOD;
		}
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