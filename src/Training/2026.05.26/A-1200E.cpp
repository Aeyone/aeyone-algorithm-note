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
    int n;
    cin >> n;
    string ans;
    cin >> ans;
    for (int i = 1; i < n; i ++) {
        string p;
        cin >> p;
        int siz = min(p.size(), ans.size());
        string s = p + "#" + ans.substr(ans.size() - siz, siz);
        int m = s.size();
        s = " " + s;
        vector<int> ne(m + 1);
        for (int i = 2, j = 0; i <= m; i ++) {
            while (j && s[i] != s[j + 1]) j = ne[j];
            if (s[i] == s[j + 1]) j ++;
            ne[i] = j;
        }
        if (ne[m] < (int)p.size()) ans += p.substr(ne[m], p.size() - ne[m]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t --) {
        solve();
    }
}