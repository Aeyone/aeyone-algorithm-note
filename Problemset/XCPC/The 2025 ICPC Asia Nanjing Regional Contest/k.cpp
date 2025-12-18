#include <bits/stdc++.h>
#define int long long
#define ll long long
#define debug(x) cerr << #x << "=" << x << "\n"
#define debug2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << "\n"
#define all(v) v.begin(), v.end()
#define all1(v) v.begin() + 1, v.end()


using namespace std;


const int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
const int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};
const int dxx[] = {1, 1, -1, -1, 0, 0, 0, 0};
const int dyy[] = {0, 0, 0, 0, 1, 1, -1, -1};
void solve()
{
    int s[2] {};
    int t[2] {};
    cin >> s[0] >> s[1] >> t[0] >> t[1];
    vector<vector<int>> g(20, vector<int>(20));
    g[t[0]][t[1]] = 1;
    auto check = [&](int x, int y)->bool{
        if (x >= 1 && x <= 9 && y >= 1 && y <= 10)
            return 1;
        else
            return 0;
    };
    int f = 0;
    for (int i = 0; i < 8; i++)
    {
        int x = s[0], y = s[1];
        int fx = x + dxx[i];
        int fy = y + dyy[i];
        if (check(fx, fy))
        {
            if (g[fx][fy])
                continue;
        }
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (check(nx, ny))
        {
            if (nx == t[0] && ny == t[1])
            {
                cout << "NO\n";
                return;
            }
            if (nx != t[0] && ny != t[1])
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cout << fixed << setprecision(10);
    int _ = 1;
    cin >> _ ;
    while (_--)
        solve();
    return 0;
}