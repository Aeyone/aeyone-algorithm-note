#include <bits/stdc++.h>
#define ll long long
#define int long long
#define debug(x) std::cerr << #x << "=" << x << "\n"
#define debug2(x, y) std::cerr << #x << "=" << x << "," << #y << "=" << y << "\n"
#define all(v) v.begin(), v.end()
#define all1(v) v.begin() + 1, v.end()



using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

using namespace std;

int f[2][105][105];

void solve() {
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    for (int k = 0; k <= 1; k++)
        for (int i = 0; i <= x; i++)
            for (int j = 0; j <= y; j++)
                f[k][i][j] = 1e9;
    f[0][x][y] = 0;
    for (int i = x; i >= 0; i--)
    {
        for (int k = 0; k < 2; k++)
        {
            if (!k)
            {
                for (int j = y; j >= 0; j--)
                {
                    if (j - i > q && i)
                        continue;
                    for (int dx = 0; dx <= p && i + dx <= x; dx++)
                    {
                        for (int dy = 0; dy + dx <= p && j + dy <= y; dy++)
                        {
                            f[1][i][j] = min(f[1][i][j], f[0][i + dx][j + dy] + 1);
                        }
                        // debug2(i, j);
                        // debug(f[1][i][j]);
                    }
                }
            }
            else
            {
                for (int j = 0; j <= y; j++)
                {
                    if ((y - j) - (x - i) > q && x - i)
                        continue;
                    for (int dy = 0; dy <= p && j - dy >= 0; dy++)
                    {
                        f[0][i][j] = min(f[0][i][j], f[1][i][j - dy] + 1);
                    }
                    // debug2(i, j);
                    // debug(f[0][i][j]);
                }
            }
        }
    }
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++)
            cout << f[0][i][j] << " \n"[j == y];
    cout << '\n';
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++)
            cout << f[1][i][j] << " \n"[j == y];
    int ans = 1e9;
    for (int j = 0; j <= y; j++)
        ans = min({ans, f[1][0][j]});
    if (ans == 1e9)
        ans = -1;
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_ --) {
        solve();
    }
}