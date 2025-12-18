#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> g(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	auto check = [&](int x)->bool{
		int tot = n;
		vector<int> siz(n);
		auto dfs = [&](auto &&self, int u, int fa)->int{
			int res = 0;
			siz[u] = 1;
			for(auto v : g[u]) if(v != fa){
				res += self(self, v, u);
				siz[u] += siz[v];
			}
			if(siz[u] >= x && tot - siz[u] >= x)
				tot -= siz[u], siz[u] = 0, res ++;
			return res;
		};
		return (dfs(dfs, 0, -1) >= k);
	};
	
	int l = 1, r = n, ans = 1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid))
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}