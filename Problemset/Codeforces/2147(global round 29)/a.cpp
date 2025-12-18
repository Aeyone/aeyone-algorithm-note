#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int x, y;
	cin >> x >> y;
	if(x < y)
		cout << 2 << '\n';
	else if(x > y + 1 && y > 1)
		cout << 3 << '\n';
	else
		cout << -1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}