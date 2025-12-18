#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int l, r;
	cin >> l >> r;
	cout << r - l + (l == 1 && r == 1) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}