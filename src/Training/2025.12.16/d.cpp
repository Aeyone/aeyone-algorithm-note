#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve () {
    int n, m;
    cin >> n >> m;
    vector<vector<i64>> g (n + 1, vector<i64> (n + 1, 1e16));

    for (int i = 0;i <= n;i++)g[i][i] = 0;

    for (int i = 0;i < m;i++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        if (w >= g[u][v])continue;
        g[u][v] = g[v][u] = w;
    }

    i64 k, t;
    cin >> k >> t;
    for (int i = 0;i < k;i++) {
        int u;cin >> u;
        g[0][u] = 0;
        g[u][0] = t;
    }

    for (int k = 0; k <= n; k ++) {
        for (int i = 0;i <= n;i ++) {
            for (int j = 0;j <= n;j ++) {
                g[i][j] = min (g[i][j], g[i][k] + g[k][j]);
            }
        }
    }


    int q;cin >> q;
    while (q--) {
        int op;cin >> op;
        if (op == 1) {
            i64 u, v, w;
            cin >> u >> v >> w;

            g[u][v] = g[v][u] = min (g[u][v], w);

            for (int i = 0;i <= n;i++) {
                for (int j = 0;j <= n;j++) {
                    g[i][j] = min (g[i][j], g[i][u] + g[u][j]);
                }
            }

            for (int i = 0;i <= n;i++) {
                for (int j = 0;j <= n;j++) {
                    g[i][j] = min (g[i][j], g[i][v] + g[v][j]);
                }
            }
        }
        if (op == 2) {
            int u;cin >> u;
            g[0][u] = 0;
            g[u][0] = t;

            for (int i = 0;i <= n;i++) {
                for (int j = 0;j <= n;j++) {
                    g[i][j] = min (g[i][j], g[i][0] + g[0][j]);
                }
            }
            for (int i = 0;i <= n;i++) {
                for (int j = 0;j <= n;j++) {
                    g[i][j] = min (g[i][j], g[i][u] + g[u][j]);
                }
            }

        }
        if (op == 3) {
            i64 ans = 0;
            for (int i = 1;i <= n;i++) {
                for (int j = 1;j <= n;j++) {
                    if (g[i][j] == 1e16)continue;
                    ans += g[i][j];
                }
            }
            cout << ans << "\n";
        }
    }

}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int _ = 1;
    // cin >> _;
    while (_ --){
        solve();
    }
}