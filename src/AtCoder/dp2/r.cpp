#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

struct SCC {
    int n;
    vector<vector<int>> adj;
    vector<int> dfn, low, bel;
    vector<int> stk, siz;
    int t, sccCnt;
    
    SCC() {}
    SCC(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        siz.clear();
        t = sccCnt = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void dfs(int u) {
        dfn[u] = low[u] = t ++;
        stk.push_back(u);
        
        for (auto y : adj[u]) {
            if (dfn[y] == -1) {         // dfn序未分配，代表树边，继续递归
                dfs(y); 
                low[u] = min(low[u], low[y]);
            } else if (bel[y] == -1) {  // dfn序分配了，但是没有分配强连通分量，代表回边
                low[u] = min(low[u], dfn[y]);
            }                           // 否则为弃边，不进行考虑
        }
        
        if (dfn[u] == low[u]) {
            int v, cnt = 0;
            do {
                v = stk.back();
                bel[v] = sccCnt;
                stk.pop_back();
                cnt ++;
            } while (v != u);
            siz.push_back(cnt);
            sccCnt ++;
        }
    }
    
    vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }
};

void solve() {
    int n;
    cin >> n;
    vector a(n + 1, vector<int>(n + 1));
    SCC scc(n + 1);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> a[i][j];
            if (a[i][j]) {
                scc.addEdge(i, j);
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        scc.addEdge(i, n);
    }

    vector<int> bel = scc.work(), w = scc.siz;
    int m = scc.sccCnt;
    vector<set<int>> g(m);
    vector<int> in(m);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (a[i][j] && bel[i] != bel[j]) {
                g[bel[i]].insert(bel[j]);
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        g[bel[i]].insert(bel[n]);
    }

    vector dp(m, vector<int>(m));

    int ans = 0;
    for (int i = m - 1; i >= 0; i --) {
        for (int j = m - 1; j >= 0; j --) {
            dp[i][j] = max(dp[i][j], i == j ? w[i] : w[i] + w[j]);

            ans = max(ans, dp[i][j]);
            if (i >= j) { 
                for (auto k : g[i]) {
                    dp[k][j] = max(dp[k][j], dp[i][j] + (k != j ? w[k] : 0));
                }
            }
            if (j >= i) {
                for (auto k : g[j]) {
                    dp[i][k] = max(dp[i][k], dp[i][j] + (k != i ? w[k] : 0));
                }
            }
        }
    }

    cout << ans - 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int _ = 1;
    while (_ --) {
        solve();
    }
}