#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> rg(n);
	map<pair<int, int>, int> mp;
	int idx = 1;
	for(auto &[u, v] : rg){
		cin >> u >> v;
		mp[{u, v}] = idx ++;
	}
	sort(rg.begin(), rg.end());
	vector<int> res;
	int L = -1e9, R = -1e9;
	for(auto [l, r] : rg){
		if(l == L){
			R = max(R, r);
			continue;
		}
		if(R > 0)
			res.push_back(mp[{L, R}]);
		L = l, R = r;
		// cout << L << " " << R << '\n';
	}
	if(R > 0)
		res.push_back(mp[{L, R}]);

	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for(auto e : res)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}