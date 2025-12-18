#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 a, b, k;
	cin >> a >> b >> k;
	i64 g = __gcd(a, b);
	a /= g, b /= g;
	i64 x = max(a, b);
	if(a == b || k >= x)
		cout << 1 << '\n';
	else
		cout << 2 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}