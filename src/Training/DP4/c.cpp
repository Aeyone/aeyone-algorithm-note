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
    int n1, n2, n3, n4, w1, w2, w3, w4;
    cin >> n1 >> w1;
    cin >> n2 >> w2;
    cin >> n3 >> w3;
    cin >> n4 >> w4;
    cout << double(w1) / n1 / 4 + double(w2) / n2 / 4 + double(w3) / n3 / 4 + double(w4) / n4 / 4 << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    // cin >> t;
    while (t --) {
        solve();
    }
}