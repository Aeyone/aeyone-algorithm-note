#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	int cnt = 0;
	i64 ans = 0;
	while(cnt < min(k, n))
		ans += cnt ++;
	ans += (i64)n * (k - cnt);

	vector<i64> s(n + 1);
	for(int i = 1; i <= n; i ++)
		s[i] = s[i - 1] + a[i - 1];

	i64 mx = 0;
	for(int l = 1, r = min(k, n); r <= n; l ++, r ++)
		mx = max(mx, s[r] - s[l - 1]);

	cout << ans + mx << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}