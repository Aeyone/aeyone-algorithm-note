#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	vector<i64> f(n);
	i64 c1 = (a[0] == 1), res = 0;
	for(int i = 1; i < n; i ++){
		f[i] = f[i - 1];
		if(a[i] == 1)
			c1 ++;
		if(a[i] == 3)
			res = (res + f[i]) % mod;
		if(a[i] == 2)
			f[i] = (2 * f[i - 1] % mod + c1) % mod;
	}
	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}