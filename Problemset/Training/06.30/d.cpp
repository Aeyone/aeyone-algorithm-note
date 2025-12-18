#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int x, y;
	cin >> x >> y;
	int n = 1;
	if(x == y)
		n = x;
	if(x > y)
		n = x + y;
	if(x < y){
		if(y % x == 0)
			n = x;
		else{
			int k = max(1, y / x - 1);
			n = k * x / 2 + y / 2;
		}
	}
	cout << n << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}