#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int xa[2], ya[2], za[2], xb[2], yb[2], zb[2];
	cin >> xa[0] >> ya[0] >> za[0] >> xa[1] >> ya[1] >> za[1];
	cin >> xb[0] >> yb[0] >> zb[0] >> xb[1] >> yb[1] >> zb[1];

	if(xa[1] <= xb[0] || ya[1] <= yb[0] || za[1] <= zb[0] || xb[1] <= xa[0] || yb[1] <= ya[0] || zb[1] <= za[0]){
		cout << "No" << '\n';
	}else{
		cout << "Yes" << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}