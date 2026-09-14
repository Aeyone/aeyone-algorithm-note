#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int n;
	cin >> n;
	vector<int> a(2 * n), s(2 * n + 1);
	for (int i = 0; i < n; i ++) {
		cin >> a[n + i];
		a[i] = a[n + i];
	}
	for (int i = 1; i < 2 * n; i ++) {
		s[i] = s[i - 1] + a[i];
	}
	if (n == 1) {
		cout << a[n] << '\n';
		return;
	}
	int ans = INF;
	for (int i = 1; i < n; i ++) {
		int cost = (s[n] - s[i - 1]) * 2 - a[i];
		int cnt = i - 1;
		cost += cnt * (a[i] + a[i + 1]);
		// cout << "i, cost = " << i << ' ' << cost << '\n';
		ans = min(ans, cost);
	}
	for (int i = n + 1; i < 2 * n; i ++) {
		int cost = (s[i] - s[n - 1]) * 2 - a[i];
		int cnt = 2 * n - 1 - i;
		cost += cnt * (a[i - 1] + a[i]);
		// cout << "i, cost = " << i << ' ' << cost << '\n';
		ans = min(ans, cost);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}