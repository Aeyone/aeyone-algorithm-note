#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

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
	int n, m;
	cin >> n >> m;
	// vector<array<int, 3>> edge(m);
	// for (auto &[u, v, w] : edge) {
	// 	cin >> u >> v >> w;
	// 	u --, v --;
	// }
	vector<vector<array<int, 2>>> a(n);
	for (int i = 0; i < m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}

	vector b(n, vector<i64>(n, INFLL));
	for (int i = 0; i < n; i ++) {
		Dinic<i64> d(n);

		vector<int> vis(n);
		queue<int> q;
		vis[i] = true;
		q.push(i);

		while (q.size()) {
			auto u = q.front();
			q.pop();
			for (auto [v, w] : a[u]) {
				d.addEdge(u, v, w);
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
		// for (auto [u, v, w] : edge) {
		// 	d.addEdge(u, v, w);
		// 	d.addEdge(v, u, w);
		// }
		b[i][i] = 0;
		for (int j = i + 1; j < n; j ++) {
			b[i][j] = b[i][j - 1] + d.flow(i, j);
			// cerr << b[i][j] << ' ';
		}
		b[i][i] = INFLL;
		// cerr << '\n';
	}

	vector<int> vis(n);
	vector<i64> dis(n, INFLL);
	using T = array<int, 2>;
	priority_queue<T, vector<T>, greater<T>> pq;
	dis[0] = 0;
	pq.push({dis[0], 0});

	i64 ans = 0;
	while (pq.size()) {
		auto [d, u] = pq.top();
		pq.pop();

		if (vis[u]) continue;
		vis[u] = true;
		ans += d;

		for (int i = 0; i < n; i ++) {
			if (!vis[i] && dis[i] > b[u][i]) {
				dis[i] = b[u][i];
				pq.push({dis[i], i});
			}
		}
	}

	cout << ans << '\n';
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