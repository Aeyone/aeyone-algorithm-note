#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

// CF915E
struct Info {
    int sum = 0;    
};

struct Node {
    Info info;
    int ls = 0, rs = 0; 
};

struct Lazy {
    int st = -1;
};

Info operator+(const Info &l, const Info &r) {
    Info res;
    res.sum = l.sum + r.sum;
    return res;
}

struct SegmentTree{
    int siz, n;
    int idx = 0;//当前的下标
    vector<Node> node;
    vector<Lazy> lazy;
 
    SegmentTree() {}
    SegmentTree(int _n) {
        init(_n);
    }

    void init(int _n){
        siz = _n;
        node.assign(siz, Node());
        lazy.assign(siz, Lazy());
    }

    void setn(int _n){
        n = _n;
    }

    void apply(int &p, i64 val, int siz){
        if(p == 0){
            p = ++ idx;
        }
        node[p].info.sum = val * siz;
        lazy[p].st = val;
    }

    void down(int p, int sizL, int sizR){
        if (lazy[p].st != -1){
            apply(node[p].ls, lazy[p].st, sizL);
            apply(node[p].rs, lazy[p].st, sizR);
            lazy[p].st = -1;
        }
    }

    void up(int &p){
        node[p].info = node[node[p].ls].info + node[node[p].rs].info;
    }
    
    void modify(int &p, int l, int r, int L, int R, i64 val){
        if (L > r || R < l){
            return;
        }
        if(p == 0){
            p = ++ idx;
        }
        if (L <= l && r <= R){
            apply(p, val, r - l + 1);
        }else{
            int mid = (l + r) / 2;
            down(p, mid - l + 1, r - mid);
            modify(node[p].ls, l, mid, L, R, val);
            modify(node[p].rs, mid + 1, r, L, R, val);
            up(p);
        }
    }
    //1-based
    void modify(int L, int R, i64 val){
        if (L <= R){
            modify(node[0].ls, 1, n, L, R, val);
        }
    }
    auto query(){
        return node[1];
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    SegmentTree st(15000010);
    st.setn(n);
    for(int i = 0; i < q; i ++){
        int l, r, k;
        cin >> l >> r >> k;
        if(k == 1){
            st.modify(l, r, 1);
        }
        if(k == 2){
            st.modify(l, r, 0);
        }
        cout << n - st.query().info.sum << '\n';
    }
}

signed main() {
//  freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_ --)
        solve();
}