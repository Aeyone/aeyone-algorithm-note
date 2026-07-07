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
    vector<array<int, 2>> b;
    for (int l = 0, r = 0; l < n; l = r) {
        while (r < n && a[l] == a[r]) {
            r ++;
        }
        b.push_back({a[l], r - l});
    }
    map<int, int> mp;
    int m = b.size();
    vector<int> sp;
    for (int i = 0; i < m; i ++) {
        auto [c, l] = b[i];
        if (mp.find(c) != mp.end()) sp.push_back(i);
        mp[c] ++;
    }
    if (sp.size() > 4) {
        cout << "NO" << '\n';
        return;
    }

    auto check = [&](int idx)-> bool {
        int col = b[idx][0];
        set<pair<int, int>> st;
        for (auto [c, cnt] : mp) st.insert({cnt, c});
        bool ok = false;
        for (int i = 0; i < m; i ++) {
            auto [c, l] = b[i];
            if (l > 1 || i == idx) continue;
            
            int sum1 = mp[col], sum2 = mp[c];
            st.erase({sum1, col});
            st.erase({sum2, c});
            if (i > 0 && b[i - 1][0] == col && i - 1 != idx) sum1 --;
            if (i < n - 1 && b[i + 1][0] == col && i + 1 != idx) sum1 --;
            if (idx > 0 && b[idx - 1][0] == c && idx - 1 != i) sum2 --;
            if (idx < n - 1 && b[idx + 1][0] == c && idx + 1 != i) sum2 --;
            st.insert({sum1, col});
            st.insert({sum2, c});
            ok |= (st.rbegin()->first == 1);
            st.erase({sum1, col});
            st.erase({sum2, c});
            st.insert({mp[col], col});
            st.insert({mp[c], c});
        }
        return ok;
    };
    bool ok = false;
    ok |= (!sp.size());
    if (sp.size()) {
        if (b[sp[0] - 1][1] == 1) {
            ok |= check(sp[0] - 1);
        }
        for (auto e : sp) if (b[e][1] == 1) {
            ok |= check(e);
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
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