#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 x, y;
	cin >> x >> y;
	if(x == y){
		cout << -1 << '\n';
		return;
	}
	if(x < y)
		swap(x, y);
	int cnt = (int)log2(x) + 1;
	cout << (1ll << cnt) - x << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}