#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template<class T>
struct SegmentTree {
    struct Info {
        T sum = 0;
        friend Info operator+(const Info& l, const Info& r) {
            return { l.sum + r.sum };
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
        info[p].sum += val * len;
        lazy[p].add += val;
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 200000;
    const int Q = 200000;

    while (1) {
        auto start = chrono::high_resolution_clock::now();
        SegmentTree<i64> seg(N);
        i64 checksum = 0;
        for(int i=0;i<Q;i++){
            int l=rnd(1,N);
            int r=rnd(1,N);
            if(l>r) swap(l,r);

            if(rng()&1){
                seg.modify(l,r,1);
            }else{
                checksum += seg.query(l,r).sum;
            }
        }

        auto end = chrono::high_resolution_clock::now();

        cerr << "time = "
             << chrono::duration<double>(end-start).count()
             << "s \t "
             << "checksum = "
             << checksum << '\n';
    }
}
