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
struct MCFGraph {
	struct Edge {
		int v;
		T c, f;
		Edge(int v, T c, T f) : v(v), c(c), f(f) {}
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
	    for (int i = 0; i < n; i ++) if (h[i] == INFLL) {
	        h[i] = 0;
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
				T c = e[i].c;
				T f = e[i].f;
				if (c > 0 && dis[v] > d + h[u] - h[v] + f) {
					dis[v] = d + h[u] - h[v] + f;
					pre[v] = i;
					que.emplace(dis[v], v);
				}
			}
		}
		return dis[t] != INFLL;
	}
	
	void addEdge(int u, int v, T c, T f) {
		g[u].push_back(e.size());
		e.emplace_back(v, c, f);
		g[v].push_back(e.size());
		e.emplace_back(u, 0, -f);
	}

	pair<T, i64> flow(int s, int t) {
		T flow = 0;
		i64 cost = 0;
		h.assign(n, 0);
		SPFA(s); // 存在负初值的时候先跑一遍spfa初始化h数组保证非负性
		while (dijkstra(s, t)) {
			for (int i = 0; i < n; i ++) if (dis[i] != INFLL) {
				h[i] += dis[i];
			}
			T aug = numeric_limits<T>::max();
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
	vector<int> a(6);
	for (int i = 0; i < 6; i ++) {
		cin >> a[i];
	}	
	int s = 0, t = 18;
	MCFGraph<int> d(t + 1);
	d.addEdge(1, 1 + 11, INF, )
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}