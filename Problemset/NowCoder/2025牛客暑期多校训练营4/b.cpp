#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;

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
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> g(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> g[i];
		g[i] = "&" + g[i];
	}
	int idx = 0;
	DSU dsu(n * m + 1);
	map<pii, int> mp;
	for(int i = 1; i <= m; i ++){
		int fx = 1, fy = i;
		while(g[fx][i] == '1')
			fx ++;

		for(int j = fx; j <= n; j ++){
			if(g[j][i] == '1'){
				fx = j + 1;
				continue;
			}
			mp[{j, i}] = idx;
			dsu.merge(mp[{fx, fy}], idx);
			idx ++;
		}
	}
	vector<int> dx = {0, -1, 1}, dy = {1, 0, 0};
	vector<int> st(idx);
	vector<vector<int>> vis(n + 1, vector<int>(m + 1));

	auto dfs = [&](auto &&self, pii u)->void{
		int x = u.first, y = u.second;
		if(y == m){
			int now = dsu.find(mp[{x, y}]);
			st[now] = 1;
			return;
		}

		for(int i = 0; i < 3; i ++){
			int a = x + dx[i], b = y + dy[i];
			if(a <= 0 || b <= 0 || a > n || b > m || vis[a][b] || g[a][b] == '1')
				continue;

			vis[a][b] = 1;
			self(self, {a, b});
			int now = dsu.find(mp[{a, b}]), la = dsu.find(mp[{x, y}]);
			st[la] |= st[now];
		}
	};
	dfs(dfs, {1, 1});
	
	vector<vector<int>> vs(n + 1, vector<int>(m + 1));
	vector<int> deep(idx);
	queue<pii> q;
	for(int i = 1; i <= n; i ++)
		q.push({i, 1}), vs[i][1] = 1;
	
	while(q.size()){
		int siz = q.size();
		while(siz --){
			auto now = q.front();
			q.pop();

			int x = now.first, y = now.second;
			for(int i = 0; i < 3; i ++){
				int a = x + dx[i], b = y + dy[i];
				if(a <= 0 || b <= 0 || a > n || b > m || vs[a][b] || g[a][b] == '1')
					continue;
				vs[a][b] = true;
				q.push({a, b});
				int now = dsu.find(mp[{a, b}]), la = dsu.find(mp[{x, y}]);

				if(!dsu.cmp(now, la) && !st[now]){
					deep[now] = max(deep[now], deep[la] + 1);
				}
			}
		}
	}
	bool ok = false;
	for(int i = 0; i < idx; i ++)
		ok |= (deep[i] >= k);

	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}