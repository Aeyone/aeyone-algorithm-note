#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n), idx(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> ne(n, -1), deep(n);
	auto dfs = [&](auto &&self, int u, int fa)->bool{
		for(auto v : g[u]) if(v != fa){
			deep[v] = deep[u] + 1;
			if(self(self, v, u)){
				ne[u] = v;
			}
		}
		if(u == n - 1){
			ne[u] = 0;
		}
		return (ne[u] != -1);
	};
	dfs(dfs, 0, -1);
	for(int i = 0; i < n; i ++){
		if(ne[i] == -1){
			idx[deep[i]].push_back(i);
		}
	}
	int x = 0;
	vector<array<int, 2>> ans;
	for(int d = n - 1; d >= 1; d --){	
		if(!idx[d].size()){
			continue;
		}
		for(auto e : idx[d]){
			if(!((d ^ x) & 1)){
				x = !x;
				ans.push_back({1, -1});
			}
			ans.push_back({2, e + 1});
			ans.push_back({1, -1});
			x = !x;
		}
	}
	if(!(x & 1)){
		ans.push_back({1, -1});
	}
	int u = 0;
	while(u != n - 1){
		ans.push_back({2, u + 1});
		ans.push_back({1, -1});
		u = ne[u];
	}
	cout << ans.size() << '\n';
	for(auto [x, y] : ans){
		if(y != -1){
			cout << x << ' ' << y << '\n';
		}else{
			cout << x << '\n';
		}
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}