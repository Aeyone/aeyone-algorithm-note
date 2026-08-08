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
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int bit[32] {};
    using T = pair<int, int>;
    vector<T> v = {{0, n - 1}};
    set<T> st;
    for (int i = 30; i >= 0; i --) {
        bool ok = true;
        vector<T> vv;
        for (auto [l, r] : v) { // 枚举所有区间，判断是否存在递减
            int idx = r;
            for (int j = l; j < r; j ++) {
                int x = a[j] >> i & 1, y = a[j + 1] >> i & 1;
                ok &= (x <= y);
                if (x < y) idx = j;
            }
            vv.push_back({l, idx});
            if (idx < r) vv.push_back({idx + 1, r});
        }
        // for (auto [l, r] : st) {
        //     cerr << "l, r = " << l << ' ' << r << '\n';
        // }
        if (!ok) {
            vv.clear();
            auto it = st.begin();
            set<T> cur;
            for (auto [l, r] : v) {
                int L = l;
                for (int j = l; j < r; j ++) {
                    int x = a[j] >> i & 1, y = a[j + 1] >> i & 1;
                    if (x <= y) continue;
                    int ansL = -1, ansR = INF;
                    auto it1 = cur.lower_bound({r, -INF});
                    if (it1 != cur.end()) {
                        ansL = it1->first;
                        ansR = it1->second;
                    }
                    while (it != st.end() && it->first <= l) {
                        cur.insert({it->second, it->first});
                        if (it->second >= r && it->second <= ansR) {
                            ansL = it->first, ansR = it->second;
                        }
                        ++ it;
                    }
                    if (ansL != -1) {
                        vv.push_back({L, j});
                        cur.erase({ansR, ansL});
                        L = j + 1;
                    } else {
                        bit[i] = 1;
                        break;
                    }
                }
                vv.push_back({L, r});
                if (bit[i]) break;
            }
            if (bit[i]) {
                vv = v;
                for (auto [l, r] : v) st.insert({l, r});
            } else {
                st.clear();
                for (auto [r, l] : cur) st.insert({l, r});
            }
        }
        v = vv;
    }
    // cerr << '\n';
    int ans = 0;
    for (int i = 0; i <= 30; i ++) {
        ans |= (bit[i] << i);
    }
    cout << ans << '\n';
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