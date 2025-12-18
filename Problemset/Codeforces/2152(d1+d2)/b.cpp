#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, xk, yk, xd, yd;
	cin >> n >> xk >> yk >> xd >> yd;
	int x = 0, y = 0, dx = abs(xk - xd), dy = abs(yk - yd);
	if(yd > yk){
		y = max(min(dx - 1, n - yk), dy + yk);
	}else if(yd < yk){
		y = max(min(dx - 1, yk), dy + n - yk);
	}else if(yd == yk){
		y = max(min(dx - 1, n - yk), min(dx - 1, yk));
	}

	if(xd > xk){
		x = max(min(dy - 1, n - xk), dx + xk);
	}else if(xd < xk){
		x = max(min(dy - 1, xk), dx + n - xk);
	}else if(xd == xk){
		x = max(min(dy - 1, n - xk), min(dy - 1, xk));
	}

	cout << max(x, y) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}