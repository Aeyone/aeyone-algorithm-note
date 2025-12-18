#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n;
	cin >> n;
	int x = 0;
	while(n)
		n >>= 1ll, x ++;
	cout << (1ll << x) - 1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}