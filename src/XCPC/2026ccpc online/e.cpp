#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> c[i];
	}

	vector<int> ab(n + 1), ac(n + 1), bc(n + 1);
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		ab[a[i]] ++;
		if (ab[a[i]] == 2) cnt1 ++;
		ac[a[i]] ++;
		if (ac[a[i]] == 2) cnt2 ++;

		ab[b[i]] ++;
		if (ab[b[i]] == 2) cnt1 ++;
		bc[b[i]] ++;
		if (bc[b[i]] == 2) cnt3 ++;

		ac[c[i]] ++;
		if (ac[c[i]] == 2) cnt2 ++;
		bc[c[i]] ++;
		if (bc[c[i]] == 2) cnt3 ++;
		if (cnt1 == i + 1 || cnt2 == i + 1 || cnt3 == i + 1) ans ++;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}