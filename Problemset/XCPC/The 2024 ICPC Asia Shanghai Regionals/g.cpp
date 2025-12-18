#include <bits/stdc++.h>
#define int long long
#define ll long long
#define debug(x) cerr << #x << "=" << x << "\n"
#define debug2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << "\n"
#define all(v) v.begin(), v.end()
#define all1(v) v.begin() + 1, v.end()


using namespace std;

using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1) , b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    sort(all1(c));
    auto check1 = [&](int a, int b, int x, int mid)->bool{ //a[i] > 0
        return a * x + b >= mid;
    };

    auto check = [&](int mid)->bool{
        int ans = 0;
        vector<pair<int, int>> p, p1;
        vector<int> vis(n + 1);
        for (int i = 1; i <= n; i++)
        {

            if (a[i] > 0)
            {
                int l = 1, r = n;
                while (l < r)
                {
                    int m = l + r >> 1;
                    if (check1(a[i], b[i], c[m], mid))
                        r = m;
                    else
                        l = m + 1;
                }
                if (check1(a[i], b[i], c[l], mid))
                    p.push_back({l, n});
            }
            else if (a[i] < 0)
            {
                int l = 1, r = n;
                while (l < r)
                {
                    int m = l + r + 1 >> 1;
                    if (check1(a[i], b[i], c[m], mid))
                        l = m;
                    else
                        r = m - 1;
                }
                if (check1(a[i], b[i], c[l], mid))
                    p1.push_back({1, l});
            }
            else
            {
                if (b[i] >= mid)
                    ans++;
            }
        }

        sort(all(p));
        sort(all(p1), [&](const pii & a, const pii & b) {
            return a.second > b.second;
        });
        int idx = 1;
        for (auto [l, r] : p)
        {
            idx = max(l, idx);
            while (idx <= r && vis[idx])
                idx++;
            if (idx <= r && (!vis[idx]) )
            {
                ans++;
                vis[idx] = 1;
                idx++;
            }
        }
        idx = n;
        for (auto [l, r] : p1)
        {
            idx = min(r, idx);
            while (idx >= l && vis[idx])
                idx--;
            if (idx >= l && (!vis[idx]) )
            {
                ans++;
                vis[idx] = 1;
                idx--;
            }
        }

        return ans >= (n + 1) / 2;
    };
    int l = -4e18, r = 4e18;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << "\n";
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

/*

3
5
0 5 -2 1 2
9 -4 0 10 5
-4 -1 4 -2 4
10
-6 3 1 0 6 -2 -4 3 0 10
22 65 11 1 -34 -1 -39 -28 25 24
10 9 1 -2 -5 8 -7 -10 -7 -7
1
101
48763
651

*/