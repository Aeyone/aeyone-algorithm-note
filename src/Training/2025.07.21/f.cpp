#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k, d;
	cin >> n >> k >> d;
	vector<int> a(n), b(k);
	for(auto &e : a)
		cin >> e;
	for(auto &e : b)
		cin >> e;

	int ans = 0;
	//最多不超过2 * n天 否则一定不如一开始就清空 然后交替
	for(int i = 0; i < min(d, max(2 * n, k)); i ++){
		int c = 0;
		for(int j = 0; j < n; j ++)
			c += (a[j] == j + 1);
		ans = max(ans, c + (d - i - 1) / 2);

		for(int j = 0; j < b[i % k]; j ++)
			a[j] ++;
	}
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