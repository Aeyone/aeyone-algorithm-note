#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	int a = 2 * (n / 5), b = ((n + 5) / 10), c = 3 * (n / 20), d = 2 * (n - (n / 20));
	cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}