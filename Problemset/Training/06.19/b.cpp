#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	if(n == 1){
		cout << 1 << ' ' << 1 << '\n';
		cout << -1 << '\n';

		cout << 1 << ' ' << 1 << '\n';
		cout << -1 << '\n';

		cout << 1 << ' ' << 1 << '\n';
		cout << -(a[1] - 2) << '\n';
		return;
	}
	cout << 1 << ' ' << 1 << '\n';
	cout << -a[1] << '\n';
	a[1] = 0;

	cout << 2 << ' ' << n << '\n';
	for(int i = 2; i <= n; i ++){
		i64 u = a[i] % n;
		a[i] += u * (n - 1);
		cout << u * (n - 1) << ' ';
	}
	cout << '\n';

	cout << 1 << ' ' << n << '\n';
	for(int i = 1; i <= n; i ++)
		cout << -a[i] << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}