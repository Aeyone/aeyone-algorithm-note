#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int x, y;
	cin >> x >> y;
	int c = __gcd(x, y);
	if(x + c > y && y + c > x)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}