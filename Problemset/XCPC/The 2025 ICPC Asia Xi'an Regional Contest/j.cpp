#include <bits/stdc++.h>
using namespace std;

#define int long long

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> c(n), w(n), deep(n), fa(n);
	for(auto &e : c){
		cin >> e;
	}
	w = c;
	vector<vector<int>> g(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	auto init = [&](auto &&self, int u)->void{
		vector<int> arr;
		for(auto v : g[u]) if(v != fa[u]){
			deep[v] = deep[u] + 1;
			fa[v] = u;
			self(self, v);
			arr.push_back(c[v]);
		}
		sort(arr.begin(), arr.end());
		if(arr.size() >= 2){
			c[u] = min(c[u], arr[0] + arr[1]);
		}
	};
	init(init, 0);
	auto dfs = [&](auto &&self, int u)->void{
		multiset<int> st;
		for(auto v : g[u]) if(v != fa[u]){
			self(self, v);
			st.insert(c[v]);
		}
		for(auto v : g[u]) if(v != fa[u]){
			st.erase(st.find(c[v]));
			w[v] = *st.begin();
			st.insert(c[v]);
		}
	};
	dfs(dfs, 0);
	vector<vector<int>> st(n, vector<int>(21, -1)), up(n, vector<int>(21, -1));
	for(int i = 1; i < n; i ++){
		st[i][0] = w[i];
		up[i][0] = fa[i];
	}
	for(int p = 1; n >> p > 0; p ++){
		for(int i = 1; i < n; i ++){
			if(deep[i] >= (1 << p)){
				up[i][p] = up[up[i][p - 1]][p - 1];
				st[i][p] = st[i][p - 1] + st[up[i][p - 1]][p - 1];
			}
		}
	}
	while(m --){
		int x, y;
		cin >> x >> y;
		x --, y --;
		int d = deep[x] - deep[y];
		if(d < 0){
			cout << -1 << '\n';
			continue;
		}
		int sum = 0, u = x;
		while(d > 0){
			int t = __lg(d & -d);
			d -= (1 << t);
			sum += st[u][t];
			u = up[u][t];
		}
		if(u != y){
			cout << -1 << '\n';
		}else{
			cout << sum << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}