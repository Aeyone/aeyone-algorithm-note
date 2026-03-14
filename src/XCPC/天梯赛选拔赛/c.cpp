#include <bits/stdc++.h>
using namespace std;

// using ll = long long;
#define int long long
#define MOD 1000000007
#define mod 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve()
{   
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = 0;
    vector<pair<int, char>> a;

    for (int l = 0, r = 0; l < n; l = r)
    {
        while (r < n && s[l] == s[r])
        {
            r++;
        }
        a.push_back({r - l, s[l]});
    }
    int ans = 0, m = a.size();
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        if (a[i].second == '1')
        {
            for (int j = i; j < min(i + 3, m); j++)
                sum += a[j].first;
        }
        else
        {
            sum += a[i].first + (i + 1 < m ? a[i + 1].first : 0);
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
}