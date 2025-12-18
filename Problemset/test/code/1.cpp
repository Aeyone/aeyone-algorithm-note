#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;


struct Info{
    i64 mx = -INFLL;     //最大值
    i64 mx2 = -INFLL;    //次大值
    i64 hmx = -INFLL;	 //历史最大值
    i64 sum = 0;		 //区间和
    int cnt = 0;		 //最大值数量
    int len = 0;		 //区间长度
};

struct Lazy{//由于需要在第二个剪枝的时候只对最大值进行加，而次大值不需要，因此需要两个懒标记
    i64 add = 0;         //最大值的懒操作
    i64 otherAdd = 0;    //其他值的懒操作
    i64 hadd = 0;		 //最大值达到过的最大提升幅度
    i64 hotherAdd = 0;	 //除最大值以外的其他数字，达到过的最大提升幅度
};

Info operator+(const Info &l, const Info &r){
	Info res;
	res.sum = l.sum + r.sum;
	res.len = l.len + r.len;
	if(l.mx == r.mx){
		res.mx = l.mx;
		res.cnt = l.cnt + r.cnt;
		res.mx2 = max(l.mx2, r.mx2);
	}else if(l.mx > r.mx){
		res.mx = l.mx;
		res.cnt = l.cnt;
		res.mx2 = max(r.mx, l.mx2);
	}else{
		res.mx = r.mx;
		res.cnt = r.cnt;
		res.mx2 = max(l.mx, r.mx2);
	}
	res.hmx = max(l.hmx, r.hmx);
	return res;
}
struct SegmentTree{
    int n;
    vector<Info> info;
    vector<Lazy> lazy;

    SegmentTree() {}
    SegmentTree(int _n, vector<i64> &arr) {
        init(_n, arr);
    }

    void init(int _n, vector<i64> &arr) {
        n = _n;
        info.assign(n << 2, Info());
        lazy.assign(n << 2, Lazy());
        build(1, 1, n, arr);
    }

    void applyAdd(int p, i64 val1, i64 val2, i64 hval1, i64 hval2) {
    	//维护历史最值
    	info[p].hmx = max(info[p].hmx, info[p].mx + hval1);
    	lazy[p].hadd = max(lazy[p].hadd, lazy[p].add + hval1);
    	lazy[p].hotherAdd = max(lazy[p].hotherAdd, lazy[p].otherAdd + hval2);

    	info[p].sum += val1 * info[p].cnt + val2 * (info[p].len - info[p].cnt);
        info[p].mx += val1;
        info[p].mx2 += (info[p].mx2 == INFLL ? 0 : val2);
        lazy[p].add += val1;
        lazy[p].otherAdd += val2;
    }

    void down(int p) {
    	if(lazy[p].add == 0 && lazy[p].otherAdd == 0) {
    		return;
    	}
        i64 mx = max(info[2 * p].mx, info[2 * p + 1].mx);
        if(info[2 * p].mx == mx) {//左儿子存在最大
        	applyAdd(2 * p, lazy[p].add, lazy[p].otherAdd, lazy[p].hadd, lazy[p].hotherAdd);
        }else{
        	applyAdd(2 * p, lazy[p].otherAdd, lazy[p].otherAdd, lazy[p].hotherAdd, lazy[p].hotherAdd);
        }
        if(info[2 * p + 1].mx == mx) {//右儿子存在最大
        	applyAdd(2 * p + 1, lazy[p].add, lazy[p].otherAdd, lazy[p].hadd, lazy[p].hotherAdd);
        }else{
        	applyAdd(2 * p + 1, lazy[p].otherAdd, lazy[p].otherAdd, lazy[p].hotherAdd, lazy[p].hotherAdd);
        }
        lazy[p].otherAdd = lazy[p].add = lazy[p].hadd = lazy[p].hotherAdd = 0;
    }

    void up(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    //构建线段树 O(N)
    void build(int p, int l, int r, vector<i64> &arr) {
        if(l == r) {
            info[p] = Info(arr[l], -INFLL, arr[l], arr[l], 1, 1);
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid, arr);
            build(2 * p + 1, mid + 1, r, arr);
            up(p);
        }
    }

    void modify(int p, int l, int r, int L, int R, int val) {
        if(L > r || R < l) {
            return;
        }
        if(L <= l && r <= R) {
            applyAdd(p, val, val, val, val);
        }else{
            int mid = (l + r) / 2;
            down(p);
            modify(2 * p, l, mid, L, R, val);
            modify(2 * p + 1, mid + 1, r, L, R, val);
            up(p);
        }
    }

    void setmin(int p, int l, int r, int L, int R, int k) {
        if(L > r || R < l || info[p].mx < k) {   //第一个剪枝：最大值小于k不操作
            return;
        }
        if(L <= l && r <= R && info[p].mx2 < k) {//第二个剪枝：l~r被ql~qr完全包含时，且次大值小于k，只需要对最大值添加懒标记
        	applyAdd(p, k - info[p].mx, 0, k - info[p].mx, 0);
        }else{                                  //暴力下发过程
            int mid = (l + r) / 2;
            down(p);                            
            setmin(2 * p, l, mid, L, R, k);
            setmin(2 * p + 1, mid + 1, r, L, R, k);
            up(p);
        }
    }

    Info query(int p, int l, int r, int L, int R) {
        if(L > r || R < l) {   
            return Info();
        }
        Info res;
        if(L <= l && r <= R) {
        	res = info[p];
        }else{                                
            int mid = (l + r) / 2;
            down(p);                            
            res = query(2 * p, l, mid, L, R) + query(2 * p + 1, mid + 1, r, L, R);
        }
        return res;
    }

    //1-based
    void modify(int L, int R, int val) { 
        modify(1, 1, n, L , R , val);
    }
    void setmin(int L, int R, int k) {
    	setmin(1, 1, n, L , R , k);
    }
    Info query(int L, int R) { 
        return query(1, 1, n, L, R);
    }
};


void solve() {
	int n, m;
	cin >> n >> m;
	vector<i64> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	SegmentTree st(n, a);
	while(m --) {
		int op, l, r;
		cin >> op >> l >> r;
		if(op == 1) {
			int k;
			cin >> k;
			st.modify(l, r, k);
		}
		if(op == 2) {
			int k;
			cin >> k;
			st.setmin(l, r, k);
		}
		if(op == 3) {
			cout << st.query(l, r).sum << '\n';
		}
		if(op == 4) {
			cout << st.query(l, r).mx << '\n';
		}
		if(op == 5) {
			cout << st.query(l, r).hmx << '\n';
		}
		// for(int i = 1; i <= n; i ++) {
		// 	cout << st.query(i, i).hmx << ' ';
		// }
		// cout << '\n';
	}
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