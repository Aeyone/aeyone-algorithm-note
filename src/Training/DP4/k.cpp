#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

#ifdef LOCAL 
    int test = 1;
#else
    int test = 0;
#endif

const int MOD = 998244353;
const double EPS = 1e-12;

// 0 = 无解, 1 = 唯一解, 2 = 无穷多解
int gauss(vector<vector<double>> a, vector<double>& ans) {
    int n = a.size(), m = a[0].size() - 1; // 变量个数
    int row = 0;
    ans.assign(m, 0);

    for (int col = 0; col < m && row < n; col ++) {
        int max = row; // 找绝对值最大作为主元
        for (int i = row + 1; i < n; i++) {
            if (abs(a[i][col]) > abs(a[max][col])) {
                max = i;
            }
        }
        if (abs(a[max][col]) < EPS) continue;
        swap(a[row], a[max]); 

        double div = a[row][col]; // 归一
        for (int j = col; j <= m; j ++) a[row][j] /= div; 

        for (int i = 0; i < n; i ++) { // 将其他行的当前列上的数化为0
            if (i != row && abs(a[i][col]) > EPS) {
                double t = a[i][col];
                for (int j = col; j <= m; j ++) {
                    a[i][j] -= t * a[row][j];
                }
            }
        }
        row ++;
    }

    for (int i = row; i < n; i ++) { // 检查无解：0 0 0 ... = 非 0
        if (abs(a[i][m]) > EPS) {
            return 0;
        }
    }

    if (row < m) return 2; // 自由元存在，无穷多解

    for (int i = 0; i < m; i++) ans[i] = a[i][m];
    return 1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<array<int, 2>> edge(m);
    for (auto &[u, v] : edge) {
        cin >> u >> v;
        u --, v --;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<double>> mat(n - 1, vector<double>(n));
    for (int i = 0; i < n - 1; i ++) {
        mat[i][i] = 1;
        for (auto v : g[i]) if (v != n - 1) {
            mat[i][v] = -1.0 / g[v].size();
        }
    }
    mat[0][n - 1] = 1;
    vector<double> ans;
    gauss(mat, ans);

    vector<double> e(m);
    for (int i = 0; i < m; i ++) {
        auto [u, v] = edge[i];
        if (u != n - 1) e[i] += ans[u] / g[u].size();
        if (v != n - 1) e[i] += ans[v] / g[v].size();
    }
    sort(e.begin(), e.end());

    double res = 0;
    for (int i = 0; i < m; i ++) {
        res += e[i] * (m - i);
    }
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(3);
    int t = 1;
    if (test) cin >> t;
    while (t --) {
        solve();
    }
}