#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int k;
	cin >> k;
	if((k - 1) % 3 == 0 )
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}