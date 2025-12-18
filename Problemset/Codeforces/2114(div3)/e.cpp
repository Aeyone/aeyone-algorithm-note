#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	vector<vector<int>> g(n);
	for(int i = 0; i < n - 1; i ++){
		int u, v;
		cin >> v >> u;
		v --, u --;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	queue<int> q;
	vector<i64> mx(n), mn(n);
	vector<bool> vis(n, false);
	q.push(0);
	mx[0] = mn[0] = a[0];
	vis[0] = true;
	while(q.size()){
		auto u = q.front();
		q.pop();
		for(auto &e : g[u]){
			if(vis[e])
				continue;
			vis[e] = true;
			mx[e] = max(a[e], a[e] - mn[u]);
			mn[e] = min(a[e], a[e] - mx[u]);
			q.push(e);
	 	}
 	}
 	for(auto e : mx)
 		cout << e << " ";
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