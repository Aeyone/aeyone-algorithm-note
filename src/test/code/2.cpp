#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL
template <typename T>
struct Info {
    T sum = 0;

    friend Info operator+(const Info &l, const Info &r) {
        return {
            l.sum + r.sum
        };
    }
};

template <typename T>
struct Lazy {
    T add = 0, setL = 0;
    bool need = false;
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

    void init(int _n){
        n = _n;
        info.assign(n << 2, Info<T>());
        lazy.assign(n << 2, Lazy<T>());
        build(1, 1, n);
    }

    void applyAdd(int p, int len, T val){
        info[p].sum += val * len;
        lazy[p].add += val;
    }

    void applySet(int p, int len, T val){
        info[p].sum = val * len;
        lazy[p] = Lazy(0, val, true);
    }
    //如果同时有重置信息和添加信息，那么一定是先重置，不然add将无效
    void down(int p, int sizL, int sizR){
        if(lazy[p].need){
            applySet(2 * p, sizL, lazy[p].setL);
            applySet(2 * p + 1, sizR, lazy[p].setL);
            lazy[p].need = false;
        }
        if(lazy[p].add != 0){
            applyAdd(2 * p, sizL, lazy[p].add);
            applyAdd(2 * p + 1, sizR, lazy[p].add);
            lazy[p].add = 0;
        }
    }

    void up(int p){
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void build(int p, int l, int r){
        if (l == r){
            info[p] = Info<T>();
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid);
            build(2 * p + 1, mid + 1, r);
            up(p);
        }
    }
    void modify(int p, int l, int r, int L, int R, T val, int sign){
        if (L > r || R < l){
            return;
        }
        if (L <= l && r <= R){
            if(sign == 1)
                applyAdd(p, r - l + 1, val);
            if(sign == 2)
                applySet(p, r - l + 1, val);
        }else{
            int mid = (l + r) / 2;
            down(p, mid - l + 1, r - mid);
            modify(2 * p, l, mid, L, R, val, sign);
            modify(2 * p + 1, mid + 1, r, L, R, val, sign);
            up(p);
        }
    }

    Info<T> query(int p, int l, int r, int L, int R){
        if(L > r || R < l){
            return Info<T>();
        }
        Info<T> res;
        if(L <= l && r <= R){
            res = info[p];
        }else{
            int mid = (l + r) / 2;
            down(p);
            res = query(2 * p, l, mid, L, R) + query(2 * p + 1, mid + 1, r, L, R);
        }
        return res;
    }

    //1-based
    void modify(int L, int R, T val, int sign){ 
        modify(1, 1, n, L, R, val, sign);
    }
    Info<T> query(int L, int R){
        return query(1, 1, n, L, R);
    }
};

void solve() {
    int ans = 0;
    vector<array<int, 2>> bit(31);
    for(int i = 0; i <= 10; i ++){
        for(int j = 0; j < 5; j ++){
            bit[j][(i >> j & 1)] ++;
        }
        // ans += (7 ^ i);
    }
    for(int i = 0; i < 5; i ++){
        cout << bit[i][0] << ' ' << bit[i][1] << '\n';
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_ --){
        solve();
    }
}