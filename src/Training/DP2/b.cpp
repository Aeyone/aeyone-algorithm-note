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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    multiset<pair<i64, int>> st;
    i64 sum = 0;
    for (int i = 0; i < n; i ++) {
        sum += a[i];
        st.insert({sum, i + 1});
    }
    int ans = 0;
    i64 cur = 0;
    for (int i = 0; i < n; i ++) {
        auto it = st.lower_bound({k + cur, 0});
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t --) {
        solve();
    }
}