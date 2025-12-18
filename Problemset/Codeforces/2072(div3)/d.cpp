#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a)
		cin >> e;

	pair<int, pair<int, int>> ans = {-1e9 ,{-1, -1}};
	for(int i = 0; i < n; i ++){
		int c1 = 0, c2 = 0;
		for(int j = i; j < n; j ++){
			c1 += (a[j] < a[i]);
			c2 += (a[j] > a[i]);
			if(c1 - c2 > ans.first)
				ans = {c1 - c2, {i + 1, j + 1}};
		}
	}
	cout << ans.second.first << ' ' << ans.second.second << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}