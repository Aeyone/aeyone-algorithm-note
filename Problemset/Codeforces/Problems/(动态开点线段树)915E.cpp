#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct Info{
    int sum;
    int ls, rs;	
    Info(int sum = 0, int ls = 0, int rs = 0) : sum(sum), ls(ls), rs(rs) {}
};

struct Lazy{
    int st;
    Lazy(int x1 = -1) : st(x1) {}
};
 
struct SegmentTree{
    int siz, n;
    int idx = 0;
    vector<Info> info;
    vector<Lazy> lazy;
 
    SegmentTree() {}
    SegmentTree(int _n) {
        init(_n);
    }
    void init(int _n){
        siz = _n;
        info.assign(siz, Info());
        lazy.assign(siz, Lazy());
    }
    void setn(int _n){
    	n = _n;
    }
    void apply(int &p, i64 val, int siz){
    	if(p == 0)
        	p = ++ idx;
        info[p].sum = val * siz;
        lazy[p].st = val;
    }
    void down(int p, int sizL, int sizR){
        if (lazy[p].st != -1){
            apply(info[p].ls, lazy[p].st, sizL);
            apply(info[p].rs, lazy[p].st, sizR);
            lazy[p].st = -1;
        }
    }
    void up(int &p){
        info[p].sum = info[info[p].ls].sum + info[info[p].rs].sum;
    }
    void modify(int &p, int l, int r, int L, int R, i64 val){
        if (L > r || R < l)
            return;
        if(p == 0)
        	p = ++ idx;

        if (L <= l && r <= R){
            apply(p, val, r - l + 1);
        }else{
            int mid = (l + r) / 2;
            down(p, mid - l + 1, r - mid);
            modify(info[p].ls, l, mid, L, R, val);
            modify(info[p].rs, mid + 1, r, L, R, val);
            up(p);
        }
    }
    //0-based
    void modify(int L, int R, i64 val){
        if (L <= R)
            modify(info[0].ls, 1, n, L + 1, R + 1, val);
    }
   	auto query(){
        return info[1];
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
		l --, r --;
		if(k == 1)
			st.modify(l, r, 1);
		if(k == 2)
			st.modify(l, r, 0);
		// cout << "idx = " << st.idx << '\n';
		cout << n - st.info[1].sum << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}