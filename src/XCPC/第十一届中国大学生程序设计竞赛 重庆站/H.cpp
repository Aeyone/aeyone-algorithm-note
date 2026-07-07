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

void solve()
{
    i64 x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    i64 ans = INFLL;
    for (i64 dx = 0; dx <= z; dx++)
    {
        i64 curx = x + dx, cury = y + z - dx;
        i64 cur = 0;
        if (2 * b <= a + c)
        {
            i64 mi = min(curx, cury);
            cur += mi * b;
            curx -= mi;
            cury -= mi;
            if (curx)
            {
                if (2 * b <= a)
                {
                    cur += curx * b;
                }
                else
                {
                    cur += (curx / 2) * a;
                    if (curx & 1)
                    {
                        cur += min(a, b);
                    }
                }
            }

            if (cury)
            {
                if (2 * b <= c)
                {
                    cur += cury * b;
                }
                else
                {
                    cur += (cury / 2) * c;
                    if (cury & 1)
                    {
                        cur += min(c, b);
                    }
                }
            }
        }
        else
        {
            i64 t1 = curx / 2, t2 = cury / 2;
            cur += t1 * a + t2 * c;
            curx = curx & 1, cury = cury & 1;
            if (curx)
            {
                if (cury)
                {
                    cur += min(b, a + c);
                }
                else
                {
                    cur += min(b, a);
                }
            }
            else
            {
                if (cury)
                {
                    cur += min(b, c);
                }
            }
        }
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    if (test)
        cin >> t;
    while (t--)
    {
        solve();
    }
}