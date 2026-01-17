#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
const ll inf = 1e18 + 1;
const int mod = 998244353;
const ll N = 1e7;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    n = s.size();
    vector<array<int, 2>> c(n + 1);
    vector<int> a(n);
    int cnt = 0, ans = -1, cur = n;
    for (int i = n - 1; i >= 0; i--) {
        c[i][0] = c[i + 1][0] + (s[i] == '(');
        c[i][1] = c[i + 1][1] + (s[i] == ')');
        a[i] = cur;
        cur = (s[i] == '(' ? i : cur);
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            if (c[a[i]][0] && cnt + 1 <= c[a[i]][1]) {
                ans = max(ans, n - 2 * (a[i] - i));
            }
            cnt--;
        } else
            cnt++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}