#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	vector<int> fa(n);
	for(int i = 0; i < n - 1; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
		fa[u] ++, fa[v] ++;
	}

	queue<int> q;
	vector<int> vis(n);
	vector<pair<int, int>> res;
	q.push(0);
	vis[0] = 2;
	bool ok = false;
	while(q.size()){
		int x = q.front();
		q.pop();

		int cnt = 0;
		for(auto e : g[x]){
			if(vis[e])
				continue;
			q.push(e);
			if(fa[x] == 2 && !ok)
				vis[e] = vis[x], ok = true;
			else
				vis[e] = 3 - vis[x];

			if(vis[e] == 1)
				res.push_back({x + 1, e + 1});
			else if(vis[e] == 2)
				res.push_back({e + 1, x + 1});
		}
	}
	if(!ok){
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
	for(auto [a, b] : res)
		cout << a << ' ' << b << '\n';

}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}