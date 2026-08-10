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
	int s = 0, t = 2 * n + 1;
	Dinic<int> d(t + 1);
	for (int i = 1; i <= n; i ++) {
		d.addEdge(s, i, 1);
		d.addEdge(n + i, t, 1);
	}
	while (m --) {
		int u, v;
		cin >> u >> v;
		d.addEdge(u, n + v, 1);
	}
	int cnt = d.flow(s, t);

	auto es = d.edges();
	vector<vector<int>> g(n + 1);
	vector<int> in(n + 1), ans;
	for (auto [u, v, c, f] : es) {
		if (f == 0 || v == t || u == s) continue;
		g[u].push_back(v - n);
		in[v - n] ++;
	}

	for (int i = 1; i <= n; i ++) {
		if (!in[i]) {
			ans.push_back(i);
		}
	}

	for (auto u : ans) {
		cout << u << ' ';
		while (g[u].size()) {
			u = g[u][0];
			cout << u << ' ';
		}
		cout << '\n';
	}
	cout << n - cnt << '\n';
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