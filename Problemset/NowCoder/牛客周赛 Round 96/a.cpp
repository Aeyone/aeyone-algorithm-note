#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int x;
	cin >> x;
	int a = x - 5;
	double b = 0.8 * x;
	if(a < b)
		cout << 5 << '\n';
	else
		cout << 8 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}