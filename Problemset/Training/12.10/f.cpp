#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

struct Info{
    i64 sum = 0;
};

struct Lazy{
    i64 setL = 0;
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
    SegmentTree(int _n, vector<int> &arr) {
        init(_n, arr);
    }

    void init(int _n, vector<int> &arr){
        n = _n;
        info.assign(n << 2, Info());
        lazy.assign(n << 2, Lazy());
        build(1, 1, n, arr);
    }

    void apply(int p, i64 val, int siz){
        info[p].sum = val * siz % MOD;
        lazy[p].setL = val;
    }

    void down(int p, int sizL, int sizR){
        if (lazy[p].setL != 0){
            apply(2 * p, lazy[p].setL, sizL);
            apply(2 * p + 1, lazy[p].setL, sizR);
            lazy[p].setL = 0;
        }
    }

    void up(int p){
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    
    void build(int p, int l, int r, vector<int> &arr){
        if (l == r){
            info[p].sum = arr[l];
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid, arr);
            build(2 * p + 1, mid + 1, r, arr);
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
    //1-based
    void modify(int L, int R, i64 val){
        modify(1, 1, n, L, R, val);
    }
    Info query(int L, int R){
        return query(1, 1, n, L, R);
    }
};

i64 qmi(i64 a, i64 b, int p = MOD){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p) if(b & 1){
		res = a * res % p;
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	SegmentTree st(n, a);
	while(m --) {
		int l, r;
		cin >> l >> r;
		i64 val = st.query(l, r).sum * qmi(r - l + 1, MOD - 2) % MOD;
		st.modify(l, r, val);
	}
	for(int i = 1; i <= n; i ++) {
		cout << st.query(i, i).sum << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}