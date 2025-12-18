#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n, l, r, k;
	cin >> n >> l >> r >> k;
	if(n & 1){
		cout << l << '\n';
		return;
	}
	i64 x = 0;
	while((l >> x) > 0)
		x ++;
	x = (1ll << x);

	if(n == 2 || x > r){
		cout << -1 << '\n';
		return;
	}

	if(k >= n - 1)
		cout << x << '\n';
	else
		cout << l << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}