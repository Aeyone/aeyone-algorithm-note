#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int x, p;
	cin >> x >> p;
	int t = p / x;
	if(p % x == 0)
		cout << 2ll * t - 1 << '\n';
	else{
		p -= t;
		cout << 2ll * p << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}