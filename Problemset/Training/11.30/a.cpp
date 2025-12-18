#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	string s;
	cin >> s;
	vector<vector<int>> g(n);
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
	}
	vector<vector<int>> vis(n, vector<int>(2 * k + 1, -1));
	auto dfs = [&](auto &&self, int u, int cnt)->bool{
		if(vis[u][cnt] != -1){
			return vis[u][cnt];
		}
		if(cnt == 2 * k){
			vis[u][cnt] = (s[u] == 'B');
			return (s[u] == 'B');
		}
		bool ok = false;
		for(auto v : g[u]){
			ok |= self(self, v, cnt + 1);
		}
		vis[u][cnt] = !ok;
		return !ok;
	};
	if(!dfs(dfs, 0, 0)){
		cout << "Alice" << '\n';
	}else{
		cout << "Bob" << '\n';
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