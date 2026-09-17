#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

struct MCFGraph {
	struct Edge {
		int v, c, f;
		Edge(int v, int c, int f) : v(v), c(c), f(f) {}
	};
	const int n;
	vector<Edge> e;
	vector<vector<int>> g;
	vector<i64> h, dis;
	vector<int> pre;

	MCFGraph(int n) : n(n), g(n) {}

	void SPFA(int s) {
	    h.assign(n, INFLL);
	    vector<bool> vis(n);
	    queue<int> q;
	    h[s] = 0;
	    vis[s] = true;
	    q.push(s);
	    while (!q.empty()) {
	        int u = q.front();
	        q.pop();
	        vis[u] = false;
	        for (int id : g[u]) {
	            auto [v, c, cost] = e[id];
	            if (c > 0 && h[v] > h[u] + cost) {
	                h[v] = h[u] + cost;
	                if (!vis[v]) {
	                    vis[v] = true;
	                    q.push(v);
	                }
	            }
	        }
	    }
	    for (int i = 0; i < n; i++) {
	        if (h[i] == INFLL) h[i] = 0;
	    }
	}

	bool dijkstra(int s, int t) {
		dis.assign(n, INFLL);
		pre.assign(n, -1);
		using PLI = pair<i64, int>;
		priority_queue<PLI, vector<PLI>, greater<PLI>> que;
		dis[s] = 0;
		que.emplace(0, s);
		while (!que.empty()) {
			i64 d = que.top().first;
			int u = que.top().second;
			que.pop();
			if (dis[u] < d) continue;
			for (int i : g[u]) {
				int v = e[i].v;
				int c = e[i].c;
				int f = e[i].f;
				if (c > 0 && dis[v] > d + h[u] - h[v] + f) {
					dis[v] = d + h[u] - h[v] + f;
					pre[v] = i;
					que.emplace(dis[v], v);
				}
			}
		}
		return dis[t] != INFLL;
	}
	
	// 当前是求可行流，若求最大流，需要去掉f < 0的部分
	void addEdge(int u, int v, int c, int f) {
		// if (f < 0) { 
		// 	g[u].push_back(e.size());
		//  	e.emplace_back(v, 0, f);
		// 	g[v].push_back(e.size());
		//  	e.emplace_back(u, c, -f);
		// } else {
			g[u].push_back(e.size());
			e.emplace_back(v, c, f);
			g[v].push_back(e.size());
			e.emplace_back(u, 0, -f);
		// }
	}

	pair<int, i64> flow(int s, int t) {
		int flow = 0;
		i64 cost = 0;
		// h.assign(n, 0);
		SPFA(s); // 存在负初值的时候先跑一遍spfa初始化h数组保证非负性
		while (dijkstra(s, t)) {
			for (int i = 0; i < n; i ++) if (dis[i] != INFLL) {
				h[i] += dis[i];
			}
			int aug = INF;
			for (int i = t; i != s; i = e[pre[i] ^ 1].v) aug = min(aug, e[pre[i]].c);
			for (int i = t; i != s; i = e[pre[i] ^ 1].v) {
				e[pre[i]].c -= aug;
				e[pre[i] ^ 1].c += aug;
			}
			flow += aug;
			cost += i64(aug) * h[t];
		}
		return {flow, cost};
	}
};

void solve() {
	int n;
	cin >> n;
	int s = 0, t = 2 * n + 1;
	MCFGraph d1(t + 1), d2(t + 1);
	for (int i = 1; i <= n; i ++) {
		d1.addEdge(s, i, 1, 0);
		d2.addEdge(s, i, 1, 0);
		d1.addEdge(i + n, t, 1, 0);
		d2.addEdge(i + n, t, 1, 0);
		for (int j = 1; j <= n; j ++) {
			int c;
			cin >> c;
			d1.addEdge(i, n + j, 1, c);
			d2.addEdge(i, n + j, 1, -c);
		}
	}
	auto [_, min] = d1.flow(s, t);
	auto [_, max] = d2.flow(s, t);
	cout << min << '\n';
	cout << -max << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}