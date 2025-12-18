#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, l;
	cin >> n >> l;

	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	sort(a.begin(), a.end());

	int ans = 0;

	if(!count(a.begin(), a.end(), 0))
		ans = max(ans, a.front() * 2);

	if(!count(a.begin(), a.end(), l))
		ans = max(ans, (l - a.back()) * 2);

	for(int i = 1; i < n; i ++)
		ans = max(ans, a[i] - a[i - 1]);
	// cout << ans << '\n';
	printf("%.10f", (double)ans / 2);
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	// int _;
	// cin >> _;
	// while (_ --)
		solve();
}