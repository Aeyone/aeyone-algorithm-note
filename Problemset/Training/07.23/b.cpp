#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 l, r;
	cin >> l >> r;
	i64 x = l, len = 0;
	while(x <= r)
		len ++, x *= 2;
	x /= 2, len --;

	i64 mul = x / l;
	int l0 = r / mul;
	int l1;
	if(mul % 2 == 0)
		l1 = r / (mul / 2 * 3);
	else
		l1 = l - 1;

	i64 ans = (l0 - l + 1);
	if(l1 >= l){
		ans += len * (l1 - l + 1);
	}
	cout << len + 1 << ' ' << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}