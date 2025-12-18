#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> w(n), dfn(n), siz(n), idx(n);
	for(int i = 0; i < n; i ++)
		cin >> w[i];

	vector<vector<int>> g(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int T = 0;
	auto dfs = [&](auto &&self, int u, int fa)->void{
		idx[T] = u, dfn[u] = T ++;
		siz[dfn[u]] = 1;
		for(auto v : g[u]) if(v != fa){
			self(self, v, u);
			siz[dfn[u]] += siz[dfn[v]];
		}
	};
	dfs(dfs, 0, -1);
	vector<int> pre(n), suf(n + 1);//dfn序下的前缀次大值和后缀次大值

	pre[0] = w[idx[0]];
	for(int i = 1; i < n; i ++)
		pre[i] = max(pre[i - 1], w[idx[i]]);
	
	for(int i = n - 1; i >= 0; i --)
		suf[i] = max(suf[i + 1], w[idx[i]]);
	
	int ans = -1;
	for(int i = 1; i < n; i ++){//枚举dfn序
		int e = max(pre[i - 1], suf[i + siz[i]]);
		if(w[idx[i]] < e && (ans == -1 || w[ans] < w[idx[i]]))
			ans = idx[i];
	}
	cout << ans + 1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}