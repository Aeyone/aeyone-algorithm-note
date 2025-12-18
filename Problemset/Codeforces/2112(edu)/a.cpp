#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int a, x, y;
	cin >> a >> x >> y;
	if(x > y)
		swap(x, y);
	if(a < x || a > y)
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