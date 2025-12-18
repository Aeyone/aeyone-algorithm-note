/*
                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
             __.'              ~.   .~              `.__
           .'//   A    C    之   \./  之    真    理   \`.
         .'//                     |                     \`.
       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
     .'//.-"                 `-.  |  .-'                 "-.\`.
   .'//______.============-..   \ | /   ..-============.______\`.
 .'______________________________\|/______________________________`.
*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

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
	vector<int> p(n);
	for(int i = 0; i < n; i ++){
		cin >> p[i];
		p[i] --;
	}
	vector<int> vis(n), cnt(n);
	vector<array<int, 2>> ans;
	int idx = 0;
	auto dfs = [&](auto &&self)->void{
		if(idx + 1 >= n){
			idx ++;
			return;
		}
		bool ok = false;
		int u = p[idx];
		for(auto v : g[u]){
			cnt[v] ++;
		}
		while(idx + 1 < n && cnt[u] < g[u].size()){
			if(g[u].find(p[idx + 1]) == g[u].end()){
				ans.push_back({u, p[idx + 1]});
				idx ++;
				self(self);
			}
			while(idx + 1 < n && g[u].find(p[idx + 1]) != g[u].end()){
				idx ++;
				self(self);
			}
		}
	};
	while(idx < n){
		dfs(dfs);
		idx ++;
	}
	cout << ans.size() << '\n';
	for(auto [u, v] : ans){
		cout << u + 1 << ' ' << v + 1 << '\n';
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