#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k, p;
	cin >> n >> k >> p;
	k = abs(k);
	int ans = (k + p - 1) / p;
	if(ans > n)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}