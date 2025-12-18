#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct DSU {
    vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool cmp(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for(int u = 0; u < n; u ++){
		int m;
		cin >> m;
		for(int i = 0; i < m; i ++){
			int v;
			cin >> v;
			v --;
			g[u].push_back(v);
		}
	}
	int idx = 0;
	map<pair<int, int>, int> mp;
	for(int u = 0; u < n; u ++){
		for(auto v : g[u])
			mp[{u, v}] = idx ++;
	}
	DSU dsu(idx);
	for(int i = 0; i < n; i ++){
		int x = dsu.size(mp[{i, g[i][0]}]);
		if(x != 1)
			continue;
		auto dfs = [&](auto &&self, int u, int fa)->void{
			int idx = 0;
			for(int i = 0; i < g[u].size(); i ++)
				if(g[u][i] == fa)
					idx = (i + 1) % g[u].size();

			int v = g[u][idx];
			// cout << u << ' ' << v << '\n';
			if(fa != -1){
				bool ok = dsu.merge(mp[{u, v}], mp[{fa, u}]);
				if(!ok)
					return;
			}
			self(self, v, u);
		};
		dfs(dfs, i, -1);
	}
	vector<int> cnt(idx);
	for(int u = 0; u < n; u ++){
		for(auto v : g[u]){
			int a = mp[{u, v}], b = mp[{v, u}];
			if(dsu.cmp(a, b))
				cnt[dsu.find(a)] ++;
		}
	}
	for(int u = 0; u < n; u ++){
		int x = mp[{u, g[u][0]}];
		cout << (dsu.size(x) - cnt[dsu.find(x)] / 2) << '\n';
	}
	// for(auto e : cnt)
	// 	cout << e << ' ';
	// cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}