#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	vector<int> cnt(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
		cnt[u] ++, cnt[v] ++;
	}
	int mx = 0;
	for(int i = 0; i < n; i ++)
		if(cnt[mx] < cnt[i])
			mx = i;

	map<int, bool> mp;
	for(int i = 0; i < n; i ++)
		if(cnt[mx] == cnt[i])
			mp[i] = true;

	for(auto [e, _] : mp){
		int ct = 1;
		for(auto v : g[e])
			ct += (mp.find(v) != mp.end());
		if(ct != mp.size())
			mx = e;
	}
	int ans = cnt[mx];
	for(auto v : g[mx])
		cnt[v] --;

	cnt[mx] = 0;
	for(int i = 0; i < n; i ++)
		if(cnt[mx] < cnt[i])
			mx = i;

	cout << ans + cnt[mx] - 1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}