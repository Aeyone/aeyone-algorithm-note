#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int x, y;
	cin >> x >> y;
	bool ok = false;
	while(x >= 0)
		ok |= (x == y - 1), x -= 9;

	if(ok)
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