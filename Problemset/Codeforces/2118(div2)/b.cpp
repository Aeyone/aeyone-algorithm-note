#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	cout << 2 * (n - 1) - 1 << '\n';
	for(int i = 1; i <= n; i ++){
		if(i >= 3)
			cout << i << ' ' << 1 << ' ' << i - 1 << '\n';
		if(i != n)
			cout << i << ' ' << i << ' ' << n << '\n';
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