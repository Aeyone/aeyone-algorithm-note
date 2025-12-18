#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n;
	cin >> n;
	if(((n - 1) % 3 == 0) && (n - 1) / 3 & 1)
		cout << 2 << '\n';
	else
		cout << 0 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}