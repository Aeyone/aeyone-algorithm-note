#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	if(a > b){
		if((a ^ 1) == b)
			cout << y << '\n';
		else
			cout << -1 << '\n';
		return;
	}
	i64 ans = 0;
	while(a < b){
		if(a & 1)
			ans += x;
		else
			ans += min(x, y);
		a ++;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}