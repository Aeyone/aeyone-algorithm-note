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
		// 	e.emplace_back(v, 0, f);
		// 	g[v].push_back(e.size());
		// 	e.emplace_back(u, c, -f);
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
		h.assign(n, 0);
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

int find(vector<int> &v, int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), cost(n);
	vector<vector<array<int, 2>>> b(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		int x = a[i];
		for (int j = 2; j <= x / j; j ++) {
			int c = 0;
			while (x % j == 0) {
				x /= j;
				c ++;
			}
			if (c > 0) {
				cost[i] += c;
				b[i].push_back({j, c});
			}
		}
		if (x > 1) {
			cost[i] ++;
			b[i].push_back({x, 1});
		}
	}
	vector<int> tot = {1};
	set<array<int, 3>> eg;

	for (int i = 0; i < n; i ++) {

		auto dfs = [&](auto &&self, int j, int num, int cnt) -> void {
		    if (j == b[i].size()) {
		        eg.insert({a[i], num, cnt});
		        tot.push_back(num);
		        return;
		    }

		    auto [p, c] = b[i][j];

		    int pw = 1;
		    for (int k = 0; k <= c; k++) {
		        self(self, j + 1, num * pw, cnt + k);
		        pw *= p;
		    }
		};
		dfs(dfs, 0, 1, 0);
	}

	sort(a.begin(), a.end());
	sort(tot.begin(), tot.end());
	tot.erase(unique(tot.begin(), tot.end()), tot.end());
	int m = tot.size();

	int s = 0, t = n + m + 1;
	MCFGraph d(t + 1);

	for (int i = 1; i <= n; i ++) {
		d.addEdge(s, i, 1, 0);
	}
	for (int i = 1; i <= m; i ++) {
		d.addEdge(n + i, t, 1, 0);
	}
	for (auto [u, v, w] : eg) {
		d.addEdge(find(a, u), n + find(tot, v), 1, w);
	}

	auto [_, ans] = d.flow(s, t);
	i64 sum = 0;
	for (auto e : cost) sum += e;

	cout << sum - ans << '\n';
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