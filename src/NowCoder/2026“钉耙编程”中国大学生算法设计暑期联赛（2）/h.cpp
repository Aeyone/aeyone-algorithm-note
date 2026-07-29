#include <bits/stdc++.h>
using namespace std;

// #define ll long long
#define int long long
#define MOD 1000000007
#define mod 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve()
{
    int n, ok = 1;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> ans(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]].push_back(i);
    }
    sort(a.begin() + 1, a.end());
    int mn = a[1], mx = a[n];
    if (n >= 3 && mn == a[3]) {
        cout << "No" << endl;
        return;
    }
    if (n > 1 && mn == a[2]) {
        if (mx == 2 * mn - 2) {
            ans[cnt[mn][0]].push_back(cnt[mn][1]);
            for (int i = mn + 1; i <= mx; i++) {
                if (cnt[i].size() < 2) {
                    ok = 0;
                    break;
                }
                for (int j = 0; j < cnt[i].size(); j++) {
                    ans[cnt[i - 1][j % 2]].push_back(cnt[i][j]);
                }
            }
        } else
            ok = 0;
    } else {
        if (mx == 2 * mn - 1) {
            for (int i = mn + 1; i <= mx; i++) {
                if (cnt[i].size() < 2) {
                    ok = 0;
                    break;
                }
                for (int j = 0; j < cnt[i].size(); j++) {
                    if (i == mn + 1) {
                        ans[cnt[i - 1][0]].push_back(cnt[i][j]);
                    } else {
                        ans[cnt[i - 1][j % 2]].push_back(cnt[i][j]);
                    }
                }
            }
        } else
            ok = 0;
    }
    if (ok) {
        cout << "Yes" << '\n';
        for (int i = 1; i <= n; i++) {
            for (auto v : ans[i]) {
                cout << i << " " << v << '\n';
            }
        }
    } else
        cout << "No" << '\n';
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int _ = 1ll;
    cin >> _;
    while (_--) {
        solve();
    }
}
