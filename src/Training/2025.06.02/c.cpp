#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n ,a, b;
	cin >> n >> a >> b;
	bool ok = false;
	i64 x = 1;
	while(x <= n){
		ok |= ((n - x) % b == 0);
		x *= a;
		if(a == 1)
			break;
	}

	if(ok)
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