#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> cnt;
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	int len = 1;
	cnt[a[0]] = 1;
	for(int i = 1; i < n; i ++){
		if(a[i] == a[i - 1])
			len ++;
		else{
			cnt[a[i - 1]] = max(cnt[a[i - 1]], len);
			len = 1;
		}
	}
	cnt[a[n - 1]] = max(cnt[a[n - 1]], len);

	i64 ans = 1e16;
	for(auto [num, c] : cnt)
		ans = min(ans, (i64)num * (n - c));

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