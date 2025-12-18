#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x = max(a, b), y = min(a, b);
	if(x - 2 * y >= 3){
		cout << "NO" << '\n';
	}else{
		c -= a, d -= b;
		x = max(c, d), y = min(c, d);
		if(x - 2 * y >= 3)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}