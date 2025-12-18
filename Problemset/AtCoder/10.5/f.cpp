#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;
    i64 L = 0, R = 0;
    vector<i64> l(n), r(n);
    for(int i = 0; i < n; i ++){
        cin >> l[i] >> r[i];
        L += l[i], R += r[i];
    }
    if(L != 0 && R != 0 && (L / abs(L)) * (R / abs(R)) > 0){
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
    for(int i = 0; i < n; i ++){
        i64 ans = l[i];
        i64 d = min(r[i] - l[i], -L);
        ans += d, L += d;
        cout << ans << ' ';
    }
    cout << '\n';
}

signed main() {
//    freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_ --)
        solve();
}