#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	vector<int> s(n);
	s[0] = a[0];
	for(int i = 1; i < n; i ++)
		s[i] = s[i - 1] + a[i];

	int ans = 0;
	for(int i = 0; i < n - 1; i ++)
		if(s[i] == s[n - 1] - s[i])
			ans ++;
			// cout << s[i] << endl;
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