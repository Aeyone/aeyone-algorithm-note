#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int x;
	cin >> x;
	if(x & 1)
		cout << "No" << '\n';
	else
		cout << "Yes" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}