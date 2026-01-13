#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n), s(n), b(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	s[0] = a[0];
	for(int i = 1; i < n; i ++)
		s[i] = s[i - 1] + a[i];

	i64 sum = s.back();
	if(sum % 3 != 0){
		cout << 0 << '\n';
		return;
	}
	for(int i = 0; i <= n - 2; i ++)
		b[i + 1] += (s[i] == sum / 3);

	vector<i64> res(n);
	for(int i = 1; i <= n - 2; i ++)
		res[i] = res[i - 1] + b[i];
	
	i64 ans = 0;
	for(int i = 1; i <= n - 2; i ++){
		if(s[i] == 2 * sum / 3)
			ans += res[i];
		// cout << res[i] << '\n';
	}

	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}