#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	int mn = 1e9;
	for(int i = 0; i < k; i ++){
		int x;
		cin >> x;
		mn = min(mn, x);
	}
	vector<pair<int, int>> v(n);
	vector<string> tos(n);
	for(int i = 0; i < n; i ++){
		cin >> v[i].first >> tos[i];
		v[i].second = i;
	}
	sort(v.begin(), v.end(), greater<pair<int, int>>{});

	int pre = 1;
	map<string, int> mp;
	vector<int> ans(n);
	for(int i = 0; i < n; i ++){
		auto [w, idx] = v[i];
		// cout << w << ' ' << idx << '\n';
		string s = tos[idx];

		if(mp[s] < mn)
			mp[s] ++, pre ++;

		ans[idx] = pre - 1;
	}
	for(auto e : ans)
		cout << e << '\n';

}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}