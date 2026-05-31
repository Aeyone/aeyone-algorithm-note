#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;
const int N = 1e6;

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n + 1, T{});
    }

    void modify(int x, const T &v) { // 单点修改
        while(x <= n){
            a[x] += v, x += x & -x;
        }
    }

    void modify(int l, int r, const T &v) { // 区间修改(差分优化)
        modify(l, v), modify(r + 1, -v);
    }
    
    T query(int x) {// 查询1~x的和 or 单点查询(差分优化)
        T ans{};
        while(x > 0){
            ans += a[x], x -= x & -x;
        }
        return ans;
    }
    // 1-based
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), D(N + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for (int d = 1; d <= N; d ++) {
        for (int num = d; num <= N; num += d) {
            D[num] ++;
        }
    }
    vector<int> f(n + 2);
    ranges::iota(f, 0);

    auto find = [&](int x)-> int {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    };
    for (int i = n; i >= 1; i --) if (a[i] == 1) {
        f[i] = find(i + 1);
    }

    Fenwick<i64> fw(n);
    for (int i = 1; i <= n; i ++) {
        fw.modify(i, a[i]);
    }

    while (m --) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            int x = l;
            while (x <= r) {
                if (a[x] != 1) {
                    fw.modify(x, D[a[x]] - a[x]);
                    a[x] = D[a[x]];
                    if (a[x] == 2) f[x] = find(x + 1);
                }
                x = f[x + 1];
            }
        } else {
            cout << fw.query(l, r) << '\n';
        }
    }
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