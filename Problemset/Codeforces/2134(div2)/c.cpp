#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a)
		cin >> e;

	i64 ans = 0;
	for(int i = 0; i < n; i += 2){
		int mn = inf;
		if(i > 0)
			mn = min(mn, a[i - 1]);
		if(i + 1 < n)
			mn = min(mn, a[i + 1]);

		ans += max(0, (a[i] - mn));
		a[i] = min(a[i], mn);
	}
	for(int i = 0; i < n; i += 2){
		if(i + 2 >= n)
			continue;

		int sum = a[i] + a[i + 2];
		if(i + 1 < n){
			int d = max(0, sum - a[i + 1]);
			ans += d;
			a[i + 2] = max(0, a[i + 2] - d);
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}