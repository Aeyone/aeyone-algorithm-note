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

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    map<int, int> mx, my, mz;
    for (int i = 0; i < n; i ++) {
        auto &[x, y, z] = a[i];
        cin >> x >> y >> z;
        mx[x] ++;
        my[y] ++;
        mz[z] ++;
    }
    vector<int> max(n);
    for (int i = 0; i < n; i ++) {
        auto &[x, y, z] = a[i];
        max[i] = std::max({mx[x], my[y], mz[z]}) - 1;
    }
    sort(max.begin(), max.end(), greater<int>());
    for (int i = 0; i < n; i ++) {
        while (max.size() && max.back() < i) max.pop_back();
        cout << n - max.size() << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    if (test) cin >> t;
    while (t --) {
        solve();
    }
}