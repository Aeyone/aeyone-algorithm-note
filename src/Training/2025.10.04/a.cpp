#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {//有点像树形dp但是没有dp(其实就是普通的dfs)
	int n, k;
	cin >> n >> k;
	vector<int> tag(n);
	vector<vector<int>> g(n);
	for(int i = 0; i < k; i ++){
		int x;
		cin >> x;
		x --;
		tag[x] = true;
	}
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> res(n), deep(n, -inf);
	auto dfs = [&](auto &&self, int u, int fa)->void{
		vector<int> a;
		if(tag[u]){
			deep[u] = 1;
		}
		int mx = 0;
		for(auto v : g[u]) if(v != fa){
			self(self, v, u);
			if(deep[v] > 0){
				deep[u] = max(deep[u], deep[v] + 1);
				a.push_back(deep[v]);
				mx = max(mx, res[v]);
			}
		}
		if(tag[u]){
			a.push_back(0);
		}
		sort(a.begin(), a.end(), greater<int>{});

		res[u] = max(mx, (a.size() >= 2 ? a[0] + a[1] + 1 : 0));
	};
	dfs(dfs, 0, -1);
	cout << res[0] / 2 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}