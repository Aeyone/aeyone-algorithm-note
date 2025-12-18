#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<set<int>> g(n);
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].insert(v);
		g[v].insert(u);
	}
	vector<bool> vis(n, false);//是否被留下
	int cnt = 0;//被留下的数量，如果没有任何一个子节点比自己大那么就可以留下来
	for(int u = 0; u < n; u ++){
		bool ok = true;
		for(auto e : g[u])
			ok &= (e < u);
		cnt += ok;
		vis[u] = ok;
	}
	int q;
	cin >> q;
	while(q --){
		int x;
		cin >> x;
		if(x == 1){
			int u , v;
			cin >> u >> v;
			u --, v --;
			g[u].insert(v);
			g[v].insert(u);
			if(v > u && vis[u])
				vis[u] = false, cnt --;
			if(u > v && vis[v])
				vis[v] = false, cnt --;
		}
		if(x == 2){
			int u, v;
			cin >> u >> v;
			u -- , v --;
			auto it1 = g[u].find(v);
			auto it2 = g[v].find(u);
			g[u].erase(it1);
			g[v].erase(it2);
			if(v > u && !vis[u] && (g[u].size() == 0 || *(--g[u].end()) < u))
				vis[u] = true, cnt ++;
			if(u > v && !vis[v] && (g[v].size() == 0 || *(--g[v].end()) < v))
				vis[v] = true, cnt ++;
		}
		if(x == 3)
			cout << cnt << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}