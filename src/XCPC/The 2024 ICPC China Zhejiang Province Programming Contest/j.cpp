#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;

	using T = array<int, 3>;
	vector<vector<T>> g(n), tr(n);
	vector<T> val(m);

	for (int i = 0; i < m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		g[u].push_back({v, w, i});
		g[v].push_back({u, w, i});
		val[i] = {u, v, w};
	}

	vector<int> vis(n), dis(n, INFLL), edgVis(m);
	priority_queue<T, vector<T>, greater<T>> heap;

	dis[0] = 0;
	heap.push({0, 0, -1});

	while (heap.size()) {
		auto [e, u, id] = heap.top();
		heap.pop();
		// cerr << "u = " << u << '\n';
		if (vis[u]) {
			continue;
		}
		vis[u] = true;

		if (id != -1) {
			edgVis[id] = true;
			auto [p, q, w] = val[id];
			tr[p].push_back({q, w, id});
			tr[q].push_back({p, w, id});
		}
		for (auto [v, w, id] : g[u]) {
			if (!vis[v] && dis[v] > w) {
				dis[v] = w;
				heap.push({dis[v], v, id});
			}
		}
	}

	for (int i = 0; i < n; i ++) {
		if (!vis[i]) {
			cout << "-1 -1" << '\n';
			return;
		}
	}
	vector st(n + 1, vector<int>(21));
	vector mx(n + 1, vector<array<int, 2>>(21, {-INFLL, -INFLL}));
	vector<int> dep(n);

	auto dfs = [&](auto &&self, int u, int fa, int w)->void{
		// cerr << "u = " << u << '\n';
		if (fa == -1) {
			st[u][0] = u;
            dep[u] = -INFLL;
		} else {
	        st[u][0] = fa;
	        dep[u] = dep[fa] + 1;
	        mx[u][0][w & 1] = w;
        }
        for (int i = 1; i < 20; i ++) {
        	int la = st[u][i - 1];
            st[u][i] = st[la][i - 1];
            mx[u][i][0] = max(mx[u][i - 1][0], mx[la][i - 1][0]);
            mx[u][i][1] = max(mx[u][i - 1][1], mx[la][i - 1][1]);
        }
        for (auto [v, w, i] : tr[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u, w);
        }
    };
    dfs(dfs, 0, -1, 0);


    auto lca = [&](int x, int y, int op)->int{
    	int res = 0;
        if (dep[x] < dep[y]) {
            swap(x, y);
        }
        for (int i = 20; i >= 0; i --) {
            if (dep[x] - (1 << i) >= dep[y]) {
                res = max(res, mx[x][i][op]);
                x = st[x][i];
            }
        }
        if (x == y) {
        	return res;
        }
        for (int i = 20; i >= 0; i --) {
            if (st[x][i] != st[y][i]) {
                res = max(res, mx[x][i][op]);
                res = max(res, mx[y][i][op]);
                x = st[x][i];
                y = st[y][i];
            }
        }
        return max({res, mx[x][0][op], mx[y][0][op]});
    };

	int ans = 0, ans2 = INFLL;
	for (int i = 0; i < m; i ++) {
		if (edgVis[i]) {
			ans += val[i][2];
		}
	}
	for (int i = 0; i < m; i ++) {
		if (edgVis[i]) {
			continue;
		}
		auto [u, v, w] = val[i];
		int res = lca(u, v, !(w & 1));
		if (res == 0) {
			continue;
		}
		ans2 = min(ans2, ans + w - res);
	}
	if (ans2 == INFLL) {
		ans2 = -1;
	}
	if (ans & 1) {
		swap(ans, ans2);
	} 
	cout << ans << ' ' << ans2 << '\n';
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