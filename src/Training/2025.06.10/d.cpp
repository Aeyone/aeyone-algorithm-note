#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n), b(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	for(int i = 0; i < n; i ++)
		cin >> b[i];

	i64 sum = 0;
	for(int i = 0; i < n; i ++)
		sum += a[i] * b[i];

	i64 ans = sum;
	for(int i = 0; i < n; i ++){//翻转子数组问题可以以i为轴心翻转，往两边扩散统计最大值
		i64 res = sum;
		for(int l = i, r = i + 1; l >= 0 && r < n; l --, r ++){
			res = res - a[l] * b[l] - a[r] * b[r] + a[l] * b[r] + a[r] * b[l];
			ans = max(ans, res);
		}
		res = sum;
		for(int l = i - 1, r = i + 1; l >= 0 && r < n; l --, r ++){
			res = res - a[l] * b[l] - a[r] * b[r] + a[l] * b[r] + a[r] * b[l];
			ans = max(ans, res);
		}
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