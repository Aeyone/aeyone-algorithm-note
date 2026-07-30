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
    vector<int> a(n), cnt(n + 1);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<vector<int>> v = {{0}};
    for (int l = 0, r = 0; l < n; l = r) {
        set<pair<int, int>> st;
        while (r < n && (!st.size() || st.begin()->first < 4)) {
            auto it = st.find({cnt[a[r]], a[r]});
            if (it != st.end()) st.erase(it);
            cnt[a[r]] ++;
            st.insert({cnt[a[r]], a[r]});
            r ++;
        }
        if (st.rbegin()->first != 4 || st.begin()->first != 4) {
            cout << 0 << '\n';
            return;
        }
        vector<int> vv;
        for (auto [_, c] : st) {
            cnt[c] = 0;
            vv.push_back(c);
        }
        v.push_back(vv);
    }
    int m = v.size() - 1;
    vector<int> la(m + 1);
    cnt.assign(n + 1, 0);
    for (int i = m, j = m; i >= 1; i --) {
        auto check = [&](int idx) -> bool {
            for(auto e : v[idx]){
                if(cnt[e]) return false;
            }
            return true;
        };
        while (j >= 1 && check(j)) {
            for (auto e : v[j]){
                cnt[e] ++;
            }
            j --;
        }
        la[i] = j + 1;
        for (auto e : v[i]) {
            cnt[e] --;
        }
    }
    vector<i64> dp(m + 1), pre(m + 1);
    pre[0] = 1;
    for (int i = 1; i <= m; i ++) {
        int j = la[i];
        dp[i] = (pre[i - 1] - (j - 2 >= 0 ? pre[j - 2] : 0) + MOD) % MOD;
        pre[i] = (pre[i - 1] + dp[i]) % MOD;
    }
    cout << dp[m] << '\n';
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