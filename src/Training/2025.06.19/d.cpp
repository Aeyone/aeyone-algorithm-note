#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	i64 c1 = 0, c2 = 0;
	for(int i = 2; i <= n; i ++){
		i64 d = a[i] - a[i - 1];
		c1 += (d < 0 ? -d : 0);
		c2 += (d > 0 ? d : 0);
	}
	cout << c1 + c2 + abs(a[1] - c1) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}