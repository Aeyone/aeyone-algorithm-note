#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, pair<int, int>>> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i].second.first;

	i64 sum = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i].second.second;
		a[i].first = a[i].second.first + a[i].second.second;

		if(a[i].second.first > a[i].second.second)
			swap(a[i].second.first, a[i].second.second);

		sum += a[i].second.second - a[i].second.first;
	}
	sort(a.begin(), a.end());
	int pre = -1e9, ans = 1e9;
	for(auto e : a){
		ans = min(ans, max(0, e.second.first - pre));
		pre = max(pre, e.second.second);
	}
	cout << sum + 2 * ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}