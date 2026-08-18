#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

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
	
	bool merge(int x, int y) {//将y合并至x中
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
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector<string> g(n);
	for (int i = 0; i < n; i ++) {
		cin >> g[i];
	}
	int N = n * m;
	DSU dsu(N);
	for (int i = 0; i < n; i ++) { 
		for (int j = 0; j < m; j ++) {
	        if (g[i][j] == '#') continue;
	        int u = i * m + j;
	        if (i + 1 < n && g[i + 1][j] == '.') {
	            dsu.merge(u, (i + 1) * m + j);
	        }
	        if (j + 1 < m && g[i][j + 1] == '.') {
	            dsu.merge(u, i * m + j + 1);
	        }
		}
	}
	int M = 0;
	vector<int> idx(N, -1), rt(N);
	for (int i = 0; i < N; i ++) {
		rt[i] = dsu.find(i);
	}
	vector<array<int, 2>> tot(k);
	for (auto &[id1, id2] : tot) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 --, y1 --, x2 --, y2 --;
		id1 = rt[x1 * m + y1];
		id2 = rt[x2 * m + y2];
		if (idx[id1] == -1) idx[id1] = M ++;
		if (idx[id2] == -1) idx[id2] = M ++;
		id1 = idx[id1];
		id2 = idx[id2];
	}

	vector<vector<int>> d(M), ok(M, vector<int>(M));
	for (auto &[id1, id2] : tot) {
		d[id1].push_back(id2);
	}

	for (int i = 0; i < M; i ++) {
		vector<int> vis(M);
		queue<int> q;
		vis[i] = true;
		q.push(i);
		while (q.size()) {
			auto u = q.front();
			ok[i][u] = true;
			q.pop();
			for (auto v : d[u]) if (!vis[v]) {
				vis[v] = true;
				q.push(v);
			}
		}
	}

	string ans;
	while (q --) {
		int x1, x2, y1, y2;	
		cin >> x1 >> y1 >> x2 >> y2;
		x1 --, y1 --, x2 --, y2 --;
		int id1 = rt[x1 * m + y1];
		int id2 = rt[x2 * m + y2];
		if (id1 == id2) {
			ans += "1\n";
			continue;
		}
		if (idx[id1] == -1 || idx[id2] == -1 || !ok[idx[id1]][idx[id2]]) {
			ans += "0\n";
		} else {
			ans += "1\n";
		}
	}
	cout << ans;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}