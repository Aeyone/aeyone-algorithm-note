#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int a, l, r;
	cin >> a >> l >> r;
	int cnt = 0;
	while(a > 0)
		a -= r, cnt ++;
	cout << cnt << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}