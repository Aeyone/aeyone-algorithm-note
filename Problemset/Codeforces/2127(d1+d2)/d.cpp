#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 1e9 + 7;
const int MAX = 1e6;
i64 fac[MAX];

void init(){
	int n = MAX;
	fac[0] = 1;
	for(i64 i = 1; i < n; i ++)
		fac[i] = (fac[i - 1] * i) % mod;
}

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
	bool ok = true;
	i64 ans = 1;
	map<pair<int, int>, bool> vis;
	for(int i = 0; i < n; i ++){
		int c1 = 0, c2 = 0;
		bool ye = false;
		for(auto v : g[i]){
			int a = i, b = v;
			if(a > b)
				swap(a, b);

			c1 += (g[v].size() == 1);

			if(g[v].size() != 1){
				c2 ++;
				ye |= (!vis[{a, b}]);
			}
			vis[{a, b}] = true;
		}
		ok &= (c2 <= 2);

		ans = ans * fac[c1] % mod;
		if(ye)
			ans = ans * 2 % mod;
	}
	ans = ans * 2 % mod;

	// DSU dsu(n + 10);
	// dsu.merge(n, 0);
	// auto dfs = [&](auto &&self, int u, int fa)->void{
	// 	int ucol = dsu.find(u);
	// 	int col = (2 * n + 1) - ucol;
	// 	if(!ok || (col != n && col != n + 1))
	// 		return;
	// 	for(auto v : g[u]) if(v != fa){
	// 		ok &= (dsu.find(v) != ucol);
	// 		dsu.merge(col, v);
	// 		self(self, v, u);
	// 	}
	// };
	// dfs(dfs, 0, -1);
	if(ok)
		cout << ans << '\n';
	else
		cout << 0 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	init();
	cin >> _;
	while (_ --)
		solve();
}