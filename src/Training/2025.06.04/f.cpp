#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<i64> a(n), b(m);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	for(int i = 0; i < m; i ++)
		cin >> b[i];

	sort(a.begin(), a.end());//确保结果为正数
	i64 x = a[n - 1] - a[0];
	for(int i = 1; i < n; i ++)
		if(a[i] != a[i - 1])
			x = __gcd(x, a[i] - a[i - 1]);

	for(int i = 0; i < m; i ++){
		if(x)
			cout << __gcd((b[i] + (a[n - 1] % x)), x) << ' ';
		else
			cout << b[i] + a[0] << ' ';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}