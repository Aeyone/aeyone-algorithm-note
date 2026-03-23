// https://www.luogu.com.cn/problem/P3384
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

int MOD = 998244353;

template<class T>
struct SegmentTree {
    struct Info {
        T sum = 0;
        friend Info operator+(const Info& l, const Info& r) {
            return { (l.sum + r.sum) % MOD };
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
        info[p].sum = (info[p].sum + val * len % MOD) % MOD;
        lazy[p].add = (lazy[p].add + val) % MOD;
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
            info[p].sum = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(2 * p, l, mid, a);
        build(2 * p + 1, mid + 1, r, a);
        pushup(p);
    }

    void modify(int p, int l, int r, int ql, int qr, T val) {
        if (ql <= l && r <= qr) {
            apply(p, val, r - l + 1);
            return;
        }
        int mid = l + r >> 1;
        pushdown(p, mid - l + 1, r - mid);
        if (ql <= mid) {
            modify(2 * p, l, mid, ql, qr, val);
        }
        if (qr > mid) {
            modify(2 * p + 1, mid + 1, r, ql, qr, val);
        }
        pushup(p);
    }

    Info query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return info[p];
        }
        Info res{};
        int mid = l + r >> 1;
        pushdown(p, mid - l + 1, r - mid);
        if (ql <= mid) {
            res = res + query(2 * p, l, mid, ql, qr);
        }
        if (qr > mid) {
            res = res + query(2 * p + 1, mid + 1, r, ql, qr);
        }
        return res;
    }

    void build(const vector<T>& a) {
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
    int n, m, r;
    cin >> n >> m >> r >> MOD;
    r --;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> f(n), siz(n), son(n, -1), dep(n), top(n, -1), dfn(n), seg(n + 1);

    // 第一遍dfs预处理 f dep siz son 数组，son[u]为u节点的重儿子编号
    auto dfs1 = [&](this auto &&self, int u, int fa = -1)-> void {
        siz[u] = 1;
        for (auto v : g[u]) if (v != fa) {
            dep[v] = dep[u] + 1;
            f[v] = u;
            self(v, u);
            siz[u] += siz[v];
        }
        for (auto v : g[u]) if (v != fa) {
            if (son[u] == -1 || siz[son[u]] < siz[v]) {
                son[u] = v;
            }
        }
    };
    dfs1(r);

    int T = 1;
    // 第二遍dfs预处理 dfn序 反序列seg(1-based) top[u]为u节点所在的重链的头节点
    auto dfs2 = [&](this auto &&self, int u, int ftop)-> void {
        top[u] = ftop, dfn[u] = T, seg[T ++] = u;
        if (son[u] != -1) {
            self(son[u], ftop);
        }
        for (auto v : g[u]) if (v != f[u] && v != son[u]){
            self(v, v);
        }
    };
    dfs2(r, r);

    SegmentTree<i64> st(n);
    for (int i = 0; i < n; i ++) {
        st.modify(dfn[i], dfn[i], a[i]);
    }

    auto pathAdd = [&](int x, int y, int v)-> void {
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) { // 优先选择深度大的往上跳
                swap(x, y);
            }
            st.modify(dfn[top[x]], dfn[x], v);
            x = f[top[x]];
        }
        if (dfn[x] > dfn[y]) {
            swap(x, y);
        }
        st.modify(dfn[x], dfn[y], v); // 最后一定会跳到同一条链上
    };

    auto pathQuery = [&](int x, int y)-> i64 {
        i64 res = 0;
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) {
                swap(x, y);
            }
            res = (res + st.query(dfn[top[x]], dfn[x]).sum) % MOD;
            x = f[top[x]];
        }
        if (dfn[x] > dfn[y]) {
            swap(x, y);
        }
        res = (res + st.query(dfn[x], dfn[y]).sum) % MOD;
        return res;
    }; 


    while (m --) {
        int c;
        cin >> c;
        if (c == 1) {
            int x, y, v;
            cin >> x >> y >> v;
            x --, y --;
            pathAdd(x, y, v);
        } else if (c == 2) {
            int x, y;
            cin >> x >> y;
            x --, y --;
            cout << pathQuery(x, y) << '\n';
        } else if (c == 3) {
            int x, v;
            cin >> x >> v;
            x --;
            st.modify(dfn[x], dfn[x] + siz[x] - 1, v);
        } else if (c == 4) {
            int x;
            cin >> x;
            x --;
            cout << st.query(dfn[x], dfn[x] + siz[x] - 1).sum << '\n';
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