#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;

    vector<int> ne(n + 1), cnt(n + 1, 1);
    for (int i = 2, j = 0; i <= n; i ++) {
        while (j && s[i] != s[j + 1]) j = ne[j];
        if (s[i] == s[j + 1]) j ++;
        ne[i] = j;
    }
    for (int i = n; i >= 1; i --) {
        cnt[ne[i]] += cnt[i];
    }

    vector<pair<int, int>> ans;
    ans.push_back({n, 1});
    int x = ne[n];
    while (x) {
        ans.push_back({x, cnt[x]});
        x = ne[x];
    }
    ranges::sort(ans);
    cout << ans.size() << '\n';
    for (auto [l, c]: ans) {
        cout << l << ' ' << c << '\n';
    }
    
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
}