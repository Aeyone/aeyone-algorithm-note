#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n), pre(n), suf(n);
	for(auto &e : a)
		cin >> e;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < i; j ++)
			pre[i] += (a[j] > a[i]);
	}
	i64 ans = 0;
	for(int i = n - 1; i >= 0; i --){
		for(int j = n - 1; j > i; j --)
			suf[i] += (2 * n - a[i] > a[j]);

		if(suf[i] <= pre[i]){
			a[i] = 2 * n - a[i];
			ans += suf[i];
		}else
			ans += pre[i];
	}
	// for(int i = 0; i < n; i ++){
	// 	// cout << a[i] << ' ';
	// 	for(int j = 0; j < i; j ++)
	// 		ans += (a[j] > a[i]);
	// }
	// cout << '\n';
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