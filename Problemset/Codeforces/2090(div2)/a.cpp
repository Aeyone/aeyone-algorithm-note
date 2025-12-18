#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int x, y ,a;
	cin >> x >> y >> a;
	a %= (x + y);
	if(a + 0.5 > x)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}