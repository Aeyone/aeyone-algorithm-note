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

template<class T>
struct Dinic {
	struct Edge {
		int to;
		T cap;
		Edge(int to, T cap) : to(to), cap(cap) {}
	};

	int n;
	vector<Edge> e;
	vector<vector<int>> g;
	vector<int> cur, dep;

	Dinic() {}
	Dinic(int n) {
		init(n);
	}
	
	void init(int n) {
		this->n = n;
		e.clear();
		g.assign(n, {});
		cur.resize(n);
		dep.resize(n);
	}

	bool bfs(int s, int t) {
		dep.assign(n, -1);
		queue<int> q;
		dep[s] = 0;
		q.push(s);
		while (q.size()) {
			const int u = q.front();
			q.pop();
			for (int i : g[u]) {
				auto [v, c] = e[i];
				if (c > 0 && dep[v] == -1) { 
					dep[v] = dep[u] + 1;
					if (v == t) return true;
					q.push(v);
				}
			}
		}
		return false;
	}

	T dfs (int u, int t, T lim) {
		if (u == t) return lim;
		auto r = lim; // r为目前还能走多少流量
		for (int &i = cur[u]; i < g[u].size(); i ++) {
			const int j = g[u][i];
			auto [v, c] = e[j];
			if (c > 0 && dep[v] == dep[u] + 1) {
				auto a = dfs(v, t, min(r, c));
				e[j].cap -= a;
				e[j ^ 1].cap += a;
				r -= a;
				if (r == 0) return lim;
			}
		}
		return lim - r;
	}

	void addEdge(int u, int v, T c) {
		while (g.size() <= u) g.push_back({});
		while (g.size() <= v) g.push_back({});
		n = g.size();
		g[u].push_back(e.size());
		e.emplace_back(v, c);
		g[v].push_back(e.size());
		e.emplace_back(u, 0);
	}

	T flow(int s, int t) {
		T ans = 0;
		while (bfs(s, t)) {
			cur.assign(n, 0);
			ans += dfs(s, t, numeric_limits<T>::max());
		}
		return ans;
	}

	struct _Edge {
		int u, v;
		T cap;
		T flow;
	};

	vector<_Edge> edges() {
		vector<_Edge> a;
		for (int i = 0; i < e.size(); i += 2) {
			_Edge x;
			x.u = e[i + 1].to;
			x.v = e[i].to;
			x.cap = e[i].cap + e[i + 1].cap;
			x.flow = e[i + 1].cap;
			a.push_back(x);
		}
		return a;
	}
};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> a(m);
	vector<int> r(m), h(m), cur(m, 0);
	DSU dsu(n + 2);
	for (int i = 0; i < m; i ++) {
		cin >> h[i] >> r[i];
		a[i].assign(r[i], 0);
		for (auto &e : a[i]) {
			cin >> e;
			if (e == -1) e = n + 1;
		}
		for (int j = 1; j < r[i]; j ++) {
			dsu.merge(a[i][j - 1], a[i][j]);
		}
	}
	if (!dsu.cmp(0, n + 1)) {
		cout << 0 << '\n';
		return;
	}

	int s = 0, t = 1, idx = 2;
	map<pair<int, int>, int> id;
	for (int i = 0; i <= n + 1; i ++) {
		id[{i, 0}] = idx ++;
	}

	Dinic<int> d(idx);
	d.addEdge(s, id[{0, 0}], k);
	d.addEdge(id[{n + 1, 0}], t, INF);

	int T = 1;
	for (int cnt = 0; cnt < k; T ++) {
		for (int i = 0; i <= n + 1; i ++) {
			d.addEdge(id[{i, T - 1}], idx, INF);
			id[{i, T}] = idx ++;
		}
		for (int i = 0; i < m; i ++) {
			auto &v = a[i];
			int j = cur[i];
			cur[i] = (cur[i] + 1) % r[i];
			int k = cur[i];
			d.addEdge(id[{v[j], T - 1}], id[{v[k], T}], h[i]);
		}
		d.addEdge(id[{n + 1, T}], t, INF);
		cnt += d.flow(s, t);
	}
	cout << T - 1 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}