#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//染色二分图
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> cl(n, -1);
	int cnt[2] = {};
	cl[0] = 0;
	cnt[0] = 1;
	auto dfs = [&](auto &&self, int u, int fa)->void{
		for(auto v : g[u]) if(v != fa){
			if(cl[v] == -1){
				cl[v] = !cl[u];
				cnt[cl[v]] ++;
				self(self, v, u);
			}
		}
	};
	dfs(dfs, 0, -1);
	vector<int> res;
	for(int i = 0; i < n; i ++){
		if(cl[i] == (cnt[1] <= cnt[0])){
			res.push_back(i + 1);
		}
	}
	cout << res.size() << '\n';
	for(auto e : res){
		cout << e << ' ';
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