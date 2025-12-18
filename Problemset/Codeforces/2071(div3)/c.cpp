#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void dfs(int u, vector<vector<int>> &g, vector<bool> &vis){
	for(auto e : g[u]){
		if(vis[e])
			continue;
		vis[e] = true;
		dfs(e, g, vis);
		cout << e + 1<< ' ';
	}
}

void solve() {
	int n, st, en;
	cin >> n >> st >> en;
	st --, en --;
	vector<vector<int>> g(n);
	for(int i = 0; i < n - 1; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> fa(n, -1);
	queue<int> q;

	fa[st] = st;
	q.push(st);
	while(q.size()){
		auto u = q.front();
		q.pop();
		for(auto e : g[u]){
			if(fa[e] != -1)
				continue;
			fa[e] = u;
			q.push(e);
		}
	}
	int x = en;
	vector<int> to;
	vector<bool> vis(n);
	while(fa[x] != x){
		vis[x] = true;
		to.push_back(x);
		x = fa[x];
	}
	vis[st] = true;
	to.push_back(st);

	while(to.size()){
		dfs(to.back(), g, vis);
		cout << to.back() + 1 << ' ';
		to.pop_back();
	}
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