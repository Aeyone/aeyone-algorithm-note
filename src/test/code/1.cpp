#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

template<class T>
struct SegmentTree {
    struct Info {
        T sum = 0;
        T max = -INFLL;
        friend Info operator+(const Info& l, const Info& r) {
            return { l.sum + r.sum, std::max(l.max, r.max) };
        }
    };

    struct Lazy {
        T add = 0;
    };

    int n;
    vector<Info> info;
    vector<Lazy> lazy;

    SegmentTree(int n = 0) { init(n); }

    void init(int n) {
        this->n = n;
        info.assign(n << 2, Info());
        lazy.assign(n << 2, Lazy());
    }

    void apply(int p, T val, int len) {
        info[p].sum = val * len;
        info[p].max = val;
        lazy[p].add = val;
    }

    void pushup(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void pushdown(int p, int lsz, int rsz) {
        T& tag = lazy[p].add;
        if (tag != 0) {
            apply(2 * p, tag, lsz);
            apply(2 * p + 1, tag, rsz);
            tag = 0;
        }
    }

    void build(int p, int l, int r, const vector<T>& a) {
        if (l == r) {
            info[p] = {a[l], a[l]};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * p, l, mid, a);
        build(2 * p + 1, mid + 1, r, a);
        pushup(p);
    }

    void modify(int p, int l, int r, int ql, int qr, T val) {
        if (ql <= l && r <= qr) {
            apply(p, val, r - l + 1);
            return;
        }
        int mid = (l + r) / 2;
        pushdown(p, mid - l + 1, r - mid);
        if (ql <= mid) modify(2 * p, l, mid, ql, qr, val);
        if (qr > mid) modify(2 * p + 1, mid + 1, r, ql, qr, val);
        pushup(p);
    }

    Info query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return info[p];
        }
        Info res {};
        int mid = (l + r) / 2;
        pushdown(p, mid - l + 1, r - mid);
        if (ql <= mid) res = res + query(2 * p, l, mid, ql, qr);
        if (qr > mid) res = res + query(2 * p + 1, mid + 1, r, ql, qr);
        return res;
    }

    void build(const vector<T>& a) { // 1-based
        build(1, 1, n, a);
    }

    void modify(int ql, int qr, T val) {
        modify(1, 1, n, ql, qr, val);
    }

    Info query(int ql, int qr) {
        return query(1, 1, n, ql, qr);
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

    dfs1(0);
    dfs2(0, 0);
    vector<i64> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[dfn[i - 1]] = a[i];
    }

    SegmentTree<i64> st(n);
    st.build(b);

    auto pathQuery = [&](int x, int y)-> SegmentTree<i64>::Info {
        SegmentTree<i64>::Info res {};
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