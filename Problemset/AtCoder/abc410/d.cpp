#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<array<int, 2>>> g(n);
	for(int i = 0; i < m; i ++){
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		g[u].push_back({v, w});
	}

	vector<vector<int>> res(n);
	vector<int> vis(n);
	queue<int> q;
	q.push(0);
	res[0].push_back(0);
	int cnt = 0;
	while(q.size()){
		int u = q.front();
		q.pop();
		for(auto [v, w] : g[u]){
			if(vis[v] >= 2)
				continue;
			for(auto e : res[u])
				res[v].push_back(e ^ w);
			vis[v] ++;
			q.push(v);
		}
	}
	if(res[n - 1].size() == 0){
		cout << -1 << '\n';
		return;
	}
	int ans = inf;
	for(auto e : res[n - 1])
		ans = min(ans, e);
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}