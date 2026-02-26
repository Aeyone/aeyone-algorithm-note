#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;

void solve() {
    int n, m;
    cin >> n >> m;
    using Edge = array<int,3>; // to, w, id

    vector<vector<Edge>> g(n);
    vector<array<int,3>> val(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        val[i] = {u, v, w};
        g[u].push_back({v, w, i});
        g[v].push_back({u, w, i});
    }

    // Prim: build one MST, but store edge id when we pick a vertex
    vector<int> vis(n, 0);
    vector<long long> dis(n, INFLL);
    vector<int> edgVis(m, 0);
    // heap: {weight, vertex, edge_id}
    priority_queue<array<long long,3>, vector<array<long long,3>>, greater<array<long long,3>>> heap;
    dis[0] = 0;
    heap.push({0, 0, -1});

    vector<vector<pair<int,int>>> tr(n); // tree adjacency: (to, weight)

    while (!heap.empty()) {
        auto cur = heap.top(); heap.pop();
        int w = (int)cur[0];
        int u = (int)cur[1];
        int eid = (int)cur[2];
        if (vis[u]) continue;
        vis[u] = 1;
        if (eid != -1) {
            edgVis[eid] = 1;
            int a = val[eid][0], b = val[eid][1], ww = val[eid][2];
            // other endpoint is the already-in-tree one; u is newly added
            int other = (a == u ? b : a);
            tr[u].push_back({other, ww});
            tr[other].push_back({u, ww});
        }
        for (auto &e : g[u]) {
            int v = e[0], wuv = e[1], id = e[2];
            if (!vis[v] && dis[v] > wuv) {
                dis[v] = wuv;
                heap.push({dis[v], v, id});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            cout << "-1 -1\n";
            return;
        }
    }

    // prepare LCA / max-on-path by parity
    int LOG = 1;
    while ((1LL << LOG) <= n) ++LOG;
    vector<vector<int>> st(n, vector<int>(LOG, 0));
    vector<vector<array<int,2>>> mx(n, vector<array<int,2>>(LOG, {0,0}));
    vector<int> dep(n, 0);

    // dfs with parent and incoming edge weight
    function<void(int,int,int)> dfs = [&](int u, int fa, int w_in) {
        if (fa == -1) {
            st[u][0] = u;
            dep[u] = 0;
        } else {
            st[u][0] = fa;
            dep[u] = dep[fa] + 1;
            int p = (w_in & 1);
            mx[u][0][p] = w_in;
        }
        for (int i = 1; i < LOG; ++i) {
            int la = st[u][i-1];
            st[u][i] = st[la][i-1];
            mx[u][i][0] = max(mx[u][i-1][0], mx[la][i-1][0]);
            mx[u][i][1] = max(mx[u][i-1][1], mx[la][i-1][1]);
        }
        for (auto [v, w] : tr[u]) {
            if (v == fa) continue;
            dfs(v, u, w);
        }
    };
    dfs(0, -1, 0);

    auto queryMaxOnPath = [&](int x, int y, int op)->int {
        int res = 0;
        if (dep[x] < dep[y]) swap(x, y);
        // lift x up
        for (int i = LOG-1; i >= 0; --i) {
            if (dep[x] - (1LL<<i) >= dep[y]) {
                res = max(res, mx[x][i][op]);
                x = st[x][i];
            }
        }
        if (x == y) return res;
        for (int i = LOG-1; i >= 0; --i) {
            if (st[x][i] != st[y][i]) {
                res = max(res, mx[x][i][op]);
                res = max(res, mx[y][i][op]);
                x = st[x][i];
                y = st[y][i];
            }
        }
        res = max(res, mx[x][0][op]);
        res = max(res, mx[y][0][op]);
        return res;
    };

    long long ans = 0;
    for (int i = 0; i < m; ++i) if (edgVis[i]) ans += val[i][2];

    long long ans2 = INFLL;
    for (int i = 0; i < m; ++i) {
        if (edgVis[i]) continue;
        int u = val[i][0], v = val[i][1], w = val[i][2];
        int need_op = !(w & 1); // looking for opposite-parity edge on path
        int res = queryMaxOnPath(u, v, need_op);
        if (res == 0) continue; // no replaceable edge of that parity
        ans2 = min(ans2, ans + w - res);
    }
    if (ans2 >= INFLL/2) ans2 = -1;
    if (ans & 1) swap(ans, ans2);
    cout << ans << " " << ans2 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}