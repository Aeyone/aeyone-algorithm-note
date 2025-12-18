#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	
	sort(a.begin(), a.end());
	vector<int> res(n);
	int idx = 0;
	for(int i = 1; i < n; i += 2)
		res[i] = a[idx ++];
	for(int i = 0; i < n; i += 2)
		res[i] = a[idx ++];

	int ans = 0;
	for(int i = 1; i < n - 1; i ++)
		ans += (res[i] < res[i - 1] && res[i] < res[i + 1]);
	cout << ans << '\n';
	for(auto e : res)
		cout << e << ' ';
	cout << '\n';
}	

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}