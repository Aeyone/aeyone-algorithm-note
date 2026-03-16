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

struct Info{
    i64 sum = 0;
};

struct Lazy{
    i64 add = 0;
};

Info operator+(const Info &l, const Info &r){
    Info res;
    res.sum = (l.sum + r.sum) % MOD;
    return res;
}
 
struct SegmentTree{
    int n;
    vector<Info> info;
    vector<Lazy> lazy;
 
    SegmentTree() {}
    SegmentTree(int _n) {
        init(_n);
    }

    void init(int _n){
        n = _n;
        info.assign(n << 2, Info());
        lazy.assign(n << 2, Lazy());
        build(1, 1, n);
    }

    void apply(int p, i64 val, int siz){
        info[p].sum = (info[p].sum + val * siz % MOD) % MOD;
        lazy[p].add = (lazy[p].add + val) % MOD;
    }

    void down(int p, int sizL, int sizR){
        if (lazy[p].add != 0){
            apply(2 * p, lazy[p].add, sizL);
            apply(2 * p + 1, lazy[p].add, sizR);
            lazy[p].add = 0;
        }
    }

    void up(int p){
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    
    void build(int p, int l, int r){
        if (l == r){
            info[p] = Info(0);
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid);
            build(2 * p + 1, mid + 1, r);
            up(p);
        }
    }

    void modify(int p, int l, int r, int L, int R, i64 val){
        if (L > r || R < l){
            return;
        }
        if (L <= l && r <= R){
            apply(p, val, r - l + 1);
        }else{
            int mid = (l + r) / 2;
            down(p, mid - l + 1, r - mid);
            modify(2 * p, l, mid, L, R, val);
            modify(2 * p + 1, mid + 1, r, L, R, val);
            up(p);
        }
    }

    Info query(int p, int l, int r, int L, int R){
        if(L > r || R < l){
            return Info();
        }
        Info res;
        if(L <= l && r <= R){
            res = info[p];
        }else{
            int mid = (l + r) / 2;
            down(p, mid - l + 1, r - mid);
            res = query(2 * p, l, mid, L, R) + query(2 * p + 1, mid + 1, r, L, R);
        }
        return res;
    }
    // 1-based
    void modify(int L, int R, i64 val){
        modify(1, 1, n, L, R, val);
    }
    Info query(int L, int R){
        return query(1, 1, n, L, R);
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

    SegmentTree st(n);
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