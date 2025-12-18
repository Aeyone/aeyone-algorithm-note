#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int l1 = 0, r1 = n - 1, l2 = 0, r2 = n - 1;
	int c1 = 0, c2 = 0;

	while (a[l1] & 1 && l1 < n)
		l1 ++, c1 ++;
	while (a[r1] & 1 && r1 > l1)
		r1 --, c1 ++;

	while (a[l2] % 2 == 0 && l1 < n)
		l2 ++, c2 ++;
	while (a[r2] % 2 == 0 && r2 > l2)
		r2 --, c2 ++;

	cout << min(c1, c2) << '\n';
}

signed main() {
//	freopen("data.in", "r", stdin), freopen("data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _;
	cin >> _;
	while (_ --)
		solve();
}

