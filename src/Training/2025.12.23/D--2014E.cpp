#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n, m, h;
	cin >> n >> m >> h;
	vector<int> horse(n);
	for(int i = 0; i < h; i ++) {
		int x;
		cin >> x;
		horse[-- x] = true;
	}
	vector<vector<array<int, 2>>> g(n);
	for(int i = 0; i < m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	vector<array<i64, 2>> vis1(n), vis2(n), dis1(n, {INFLL, INFLL}), dis2(n, {INFLL, INFLL});
	using T = tuple<i64, int, int>;
	priority_queue<T, vector<T>, greater<T>> heap;

	auto bfs = [&](vector<array<i64, 2>> &vis, vector<array<i64, 2>> &dis)->void{
		while(heap.size()) {
			auto [d, u, sign] = heap.top();
			heap.pop();
			// cerr << "d, u, sign = " << d << ' ' << u << ' ' << sign << '\n';
			if(vis[u][sign]){
				continue;
			}
			vis[u][sign] = true;
			for(auto [v, w] : g[u]) {
				if(dis[v][sign] > d + w / (sign ? 2 : 1)) {
					dis[v][sign] = d + w / (sign ? 2 : 1);
					heap.push({dis[v][sign], v, sign | horse[v]});
				}
			}
		}
	};

	dis1[0][horse[0]] = 0;
	heap.push({0, 0, horse[0]});
	bfs(vis1, dis1);

	dis2[n - 1][horse[n - 1]] = 0;
	heap.push({0, n - 1, horse[n - 1]});
	bfs(vis2, dis2);
	i64 ans = INFLL;
	for(int i = 0; i < n; i ++) {
		i64 mx = max(min(dis1[i][0], dis1[i][1]), min(dis2[i][0], dis2[i][1]));
		ans = min(ans, mx);
	}
	cout << (ans == INFLL ? -1 : ans) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}