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
	int n, m;
	cin >> n >> m;
	vector<vector<array<int, 2>>> g(n);
	for (int i = 0; i < m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	vector<int> ans(n);
	for (int i = 0; i <= 30; i ++) {
		vector<array<int, 2>> cur(n, {-1, -1});
		vector<vector<int>> alls(2);
		auto bfs = [&](int x, int j)->int{
			int cnt = 0;
			queue<int> q;

			cur[x][j] = j;
			q.push(x);
			while (q.size()) {
				auto u = q.front();
				q.pop();
				alls[j].push_back(u);
				for (auto [v, w] : g[u]) {
					if (cur[v][j] != -1) {
						if (cur[v][j] != (w >> i & 1) ^ cur[u][j]) {
							return -1;
						}
						continue;
					}
					cur[v][j] = (w >> i & 1) ^ cur[u][j];
					cnt += cur[v][j];
					q.push(v);
				}
			}
			return cnt;
		};
		for (int j = 0; j < n; j ++) {
			if (cur[j][0] != -1 && cur[j][1] != -1) {
				continue;
			}
			int cnt[2] = {};
			cnt[0] = bfs(j, 0);
			cnt[1] = bfs(j, 1);
			if (cnt[0] == -1 || cnt[1] == -1) {
				cout << -1 << '\n';
				return;
			}
			int idx = (cnt[0] > cnt[1]);
			for (auto e : alls[idx]) {
				ans[e] += (1 << i) * cur[e][idx];
			}
			alls.assign(2, vector<int>{});
		}
	}
	for (int i = 0; i < n; i ++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
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