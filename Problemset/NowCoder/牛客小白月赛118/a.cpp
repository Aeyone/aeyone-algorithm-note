#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int x, y;
	cin >> x >> y;
	if(y == (x + 1) % 3)
		cout << "Hongwins" << '\n';
	else if(x == (y + 1) % 3)
		cout << "chengwins" << '\n';
	else
		cout << "Draw" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}