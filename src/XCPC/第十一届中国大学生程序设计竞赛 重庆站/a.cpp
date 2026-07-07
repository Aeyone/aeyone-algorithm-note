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
    int test = 1;
#endif

const int MOD = 998244353;
const int N = 1000;
int g[N + 10][N + 10];

void solve() {
    int n;
    cin >> n;
    int ans1 = 0, ans2 = 0;
    vector<array<int, 2>> p(n);
    for (auto &[x, y] : p) {
        cin >> x >> y;
    }

    auto f = [&](int col, int x, int y)-> int {
        int res = 0;
        for (int l = 1, r = 1; l <= N; l = r) {
            while (r <= N && g[x][r] == g[x][l]) {
                r ++;
            }
            if (g[x][l] == col) {
                res += max(0, r - l - 4);
            }
        }
        for (int l = 1, r = 1; l <= N; l = r) {
            while (r <= N && g[r][y] == g[l][y]) {
                r ++;
            }
            if (g[l][y] == col) {
                res += max(0, r - l - 4);
            }
        }
        int a = x - min(x, y) + 1, b = y - min(x, y) + 1;
        for (int l = 0, r = 0; max(a + l, b + l) <= N; l = r) {
            while (max(a + r, b + r) <= N && g[a + r][b + r] == g[a + l][b + l]) {
                r ++;
            }
            if (g[a + l][b + l] == col) {
                res += max(0, r - l - 4);
            }
        }
        a = x, b = y;
        while (a < N && b > 1) a ++, b --;

        for (int l = 0, r = 0; a - l >= 1 && b + l <= N; l = r) {
            while (a - r >= 1 && b + r <= N && g[a - r][b + r] == g[a - l][b + l]) {
                r ++;
            }
            if (g[a - l][b + l] == col) {
                res += max(0, r - l - 4);
            }
        }
        return res;
    };

    for (int i = 0; i < n; i ++) {
        auto [x, y] = p[i];
        if (i & 1) {
            ans2 -= f(2, x, y);
            g[x][y] = 2;
            ans2 += f(2, x, y);
            cout << ans2 << ' ';
        } else {
            ans1 -= f(1, x, y);
            g[x][y] = 1;
            ans1 += f(1, x, y);
            cout << ans1 << ' ';
        }
    }
    cout << '\n';
    for (auto [x, y] : p) g[x][y] = 0;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    if (test) cin >> t;
    while (t --) {
        solve();
    }
}