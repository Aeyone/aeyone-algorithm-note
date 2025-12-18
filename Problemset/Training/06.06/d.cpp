#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	int c = n;
	int a2 = c * c - (c - 1) * (c - 1);
	while(sqrt(a2) != (int)sqrt(a2)){
		c --;
		a2 = c * c - (c - 1) * (c - 1);
	}
	int a = sqrt(a2);
	cout << a / 2 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}