#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), L(n, -1), R(n, -1), stk;
    for(auto &e : a)
        cin >> e;

    for(int i = 0; i < n; i ++){
        while(stk.size() && a[stk.back()] < a[i])
            stk.pop_back();
        if(stk.size())
            L[i] = stk.back();
        stk.push_back(i);      
    }
    stk.clear();
    for(int i = n - 1; i >= 0; i --){
        while(stk.size() && a[stk.back()] > a[i])
            stk.pop_back();
        if(stk.size())
            R[i] = stk.back();
        stk.push_back(i);
    }
    vector<int> seg(n, 1e9);
    for(int i = 0; i < n; i ++){
        if(L[i] != -1 && R[i] != -1)
            seg[L[i]] = min(seg[L[i]], R[i]);
    }
    vector<vector<int>> st(n, vector<int>(30));
    for(int i = 0; i < n; i ++)
        st[i][0] = seg[i];
    for(int p = 1; n >> p > 0; p ++){
        for(int i = 0; i + (1 << p) <= n; i ++)
            st[i][p] = min(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
    }
    auto query = [&](int l, int r)->int{
        int p = log2(r - l + 1);
        return min(st[l][p], st[r - (1 << p) + 1][p]);
    };
    while(q --){
        int l, r;
        cin >> l >> r;
        l --, r --;
        if(r - l + 1 < 3){
            cout << "YES" << '\n';
            continue;
        }
        if(query(l, r) <= r)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
}

signed main() {
//  freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_ --)
        solve();
}