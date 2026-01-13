#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//染色法二分图
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<array<int, 2>> eg(m);
	for(auto &[u, v] : eg){
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> cl(n, -1);
	cl[0] = 0;
	auto dfs = [&](auto &&self, int u, int fa)->bool{
		for(auto v : g[u]) if(v != fa){
			if(cl[v] == -1){
				cl[v] = !cl[u];
				if(!self(self, v, u)){
					return false;
				}
			}else if(cl[v] == cl[u]){
				return false;
			}
		}
		return true;
	};
	if(dfs(dfs, 0, -1)){
		cout << "YES" << '\n';
		for(auto [u, v] : eg){
			cout << (cl[u] == 0);
		}
		cout << '\n';
	}else{
		cout << "NO" << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}