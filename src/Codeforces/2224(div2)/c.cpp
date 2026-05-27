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
    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    vector<int> prea(n + 1), preb(n + 1);
    for (int i = 1; i <= n; i ++) {
        prea[i] = prea[i - 1] + (a[i] == '(' ? 1 : -1);
        preb[i] = preb[i - 1] + (b[i] == '(' ? 1 : -1);
    }
    int dif = 0;
    for (int i = 1; i <= n; i ++) {
        cerr << a << '\n';
        cerr << b << '\n';
        cerr << '\n';
        if (a[i] == b[i]) continue;
        int sa = prea[i] + dif, sb = preb[i] - dif;
        if (sb < 0 && sa > sb && a[i] == '(') dif -= 2, swap(a[i], b[i]);
        else if (sa < 0 && sa < sb && a[i] == '(') dif += 2, swap(a[i], b[i]);
    }
    bool ok = true;
    for (int i = 1; i <= n; i ++) {
        prea[i] = prea[i - 1] + (a[i] == '(' ? 1 : -1);
        preb[i] = preb[i - 1] + (b[i] == '(' ? 1 : -1);
        ok &= (prea[i] >= 0 && preb[i] >= 0);
    }
    ok &= (prea[n] == 0 && preb[n] == 0);
    if (ok) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
}