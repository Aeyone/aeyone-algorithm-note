#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

template <typename T>
struct Info{
    T sum = 0;
    T max = -INFLL;

    friend Info operator+(const Info& l, const Info& r) {
        return {
            l.sum + r.sum,
            std::max(l.max, r.max)
        };
    }
};

template <typename T>
struct Lazy{
    T add = 0;
};

template <typename T>
struct SegmentTree {
    int n;
    vector<Info<T>> info;
    vector<Lazy<T>> lazy;
 
    SegmentTree() {}
    SegmentTree(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        info.assign(n << 2, Info<T>());
        lazy.assign(n << 2, Lazy<T>());
        build(1, 1, n);
    }

    void apply(int p, T val, int siz) {
        info[p].sum = val * siz;
        info[p].max = val;
        lazy[p].add = val;
    }

    void down(int p, int sizL, int sizR) {
        if (lazy[p].add != 0) {
            apply(2 * p, lazy[p].add, sizL);
            apply(2 * p + 1, lazy[p].add, sizR);
            lazy[p].add = 0;
        }
    }

    void up(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    
    void build(int p, int l, int r) {
        if (l == r) {
            info[p] = Info<T>();
        } else {
            int mid = (l + r) / 2;
            build(2 * p, l, mid);
            build(2 * p + 1, mid + 1, r);
            up(p);
        }
    }

    void modify(int p, int l, int r, int L, int R, T val) {
        if (L > r || R < l) {
            return;
        }
        if (L <= l && r <= R) {
            apply(p, val, r - l + 1);
        } else {
            int mid = (l + r) / 2;
            down(p, mid - l + 1, r - mid);
            modify(2 * p, l, mid, L, R, val);
            modify(2 * p + 1, mid + 1, r, L, R, val);
            up(p);
        }
    }

    Info<T> query(int p, int l, int r, int L, int R) {
        if (L > r || R < l) {
            return Info<T>();
        }
        Info<T> res;
        if (L <= l && r <= R) {
            res = info[p];
        } else {
            int mid = (l + r) / 2;
            down(p, mid - l + 1, r - mid);
            res = query(2 * p, l, mid, L, R) + query(2 * p + 1, mid + 1, r, L, R);
        }
        return res;
    }
    //1-based
    void modify(int L, int R, T val) {
        modify(1, 1, n, L, R, val);
    }
    Info<T> query(int L, int R) {
        return query(1, 1, n, L, R);
    }
};


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dep(n), f(n), siz(n), son(n, -1);
    auto dfs1 = [&](this auto &&self, int u)-> void {
        siz[u] = 1;
        for (auto v : g[u]) if (v != f[u]) {
            f[v] = u;
            dep[v] = dep[u] + 1;
            self(v);
            siz[u] += siz[v];
        }
        for (auto v : g[u]) if (v != f[u]) {
            if (son[u] == -1 || siz[v] > siz[son[u]]) {
                son[u] = v;
            }
        }
    };
    vector<int> top(n), dfn(n);
    int T = 1;

    auto dfs2 = [&](this auto &&self, int u, int ftop)-> void {
        top[u] = ftop, dfn[u] = T ++;
        if (son[u] != -1) {
            self(son[u], ftop);
        }
        for (auto v : g[u]) if (v != f[u] && v != son[u]) {
            self(v, v);
        }
    };

    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    dfs1(0);
    dfs2(0, 0);

    SegmentTree<i64> st(n);
    for (int i = 0; i < n; i ++) {
        st.modify(dfn[i], dfn[i], a[i]);
    }

    auto pathQuery = [&](int x, int y)-> Info<i64> {
        Info<i64> res = Info<i64>();
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) {
                swap(x, y);
            }
            res = res + st.query(dfn[top[x]], dfn[x]);
            x = f[top[x]];
        }
        if (dfn[x] > dfn[y]) {
            swap(x, y);
        }
        res = res + st.query(dfn[x], dfn[y]);
        return res;
    };

    int q;
    cin >> q;
    while (q --) {
        string s;
        cin >> s;
        int u, v;
        cin >> u >> v;
        u --;
        if (s == "CHANGE") {
            st.modify(dfn[u], dfn[u], v);
        } else if (s == "QMAX") {
            v --;
            cout << pathQuery(u, v).max << '\n';
        } else if (s == "QSUM") {
            v --;
            cout << pathQuery(u, v).sum << '\n';
        }
    }

}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int _ = 1;
    while (_ --) {
        solve();
    }
}