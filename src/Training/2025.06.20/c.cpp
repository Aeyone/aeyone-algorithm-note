#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	for(int i = 0; i < m; i ++)
		cin >> b[i];

	sort(b.begin(), b.end(), greater<int>());

	int h = 0;
	for(int i = 0; i < n; i ++){
		while(h < m && b[h] >= a[i])
			cout << b[h ++] << ' ';
		cout << a[i] << ' ';
	}
	while(h < m)
		cout << b[h ++] << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}