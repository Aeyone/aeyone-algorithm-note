#include <bits/stdc++.h>
using namespace std;

// #define ll long long
#define int long long
#define MOD 1000000007
#define mod 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL
#define endl '\n'
using T = array<int, 3>;

int ex_gcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    } else {
        int d = ex_gcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<array<int, 2>> d(n + 1, {INF, INF});
    d[1][0] = 0;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0, 1, 0});
    while (pq.size()) {
        auto [dist, u, op] = pq.top();
        pq.pop();
        for (auto v : g[u]) {
            if (d[v][op ^ 1] != INF)
                continue;
            d[v][op ^ 1] = dist + 1;
            pq.push({dist + 1, v, op ^ 1});
        }
    }
    vector<int> ans(n + 1, INF);
    for (int i = 2; i <= n; i ++) {
        for (int j = 0; j < 2; j ++) {
            if (d[i][j] != INF) {
                int x = 0, y = 0;
                int g = ex_gcd(2, k, x, y);
                if (d[i][j] % g == 0) {
                    int q = k / g;
                    x *= (-d[i][j] / g);
                    int mn = ((x % q) + q) % q;
                    ans[i] = min(ans[i], d[i][j] + 2 * mn);
                }
            }
        }
    }
    cout << 0 << " ";
    for (int i = 2; i <= n; i ++) {
        cout << (ans[i] == INF ? -1 : ans[i]) << ' ';
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _ = 1ll;
    cin >> _;
    while (_--) {
        solve();
    }
}