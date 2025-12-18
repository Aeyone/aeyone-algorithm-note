#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, pair<int, int>>> a(n);
	for(int i = 0; i < n; i ++){
		int x, y, z;
		cin >> x >> y >> z;
		a[i] = {z, {x, y}};
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i ++){
		if(k > a[i].first)
			continue;
		int l = a[i].second.first;
		if(k >= l && k <= a[i].first)
			k = a[i].first;
	}
	cout << k << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}