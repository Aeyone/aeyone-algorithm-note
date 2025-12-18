#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
struct Info{
    int pre = 0, suf = 0;
    bool ok = false;
};
 
struct SegmentTree{
    int n;
    vector<Info> info;
 
    SegmentTree() {}
    SegmentTree(int _n, vector<int> &a) {
        init(_n, a);
    }   

    void init(int _n, vector<int> &a){
        n = _n;
        info.assign(n << 2, Info());
        build(1, 1, n, a);
    }

    Info merge(Info l, Info r){
    	if(l.pre == -1){
    		return r;
    	}
    	if(r.suf == -1){
    		return l;
    	}
        Info res;
        res.pre = l.pre;
        res.suf = r.suf;
    	res.ok |= (l.ok || r.ok);
    	res.ok |= (l.suf == r.pre);
        return res;
    }
    
    void build(int p, int l, int r, vector<int> &a){
        if (l == r){
            info[p] = {a[l], a[r], false};
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid, a);
            build(2 * p + 1, mid + 1, r, a);
            info[p] = merge(info[2 * p], info[2 * p + 1]);
        }
    }

    Info query(int p, int l, int r, int L, int R){
        if(L > r || R < l)
            return Info(-1, -1, false);
        
        if(L <= l && r <= R)
            return info[p];
        
        int mid = (l + r) / 2;
        Info Ql = query(2 * p, l, mid, L, R);
        Info Qr = query(2 * p + 1, mid + 1, r, L, R);
        return merge(Ql, Qr);
    }
    //1-based
    Info query(int L, int R){
        if(L <= R)
            return query(1, 1, n, L, R);
        else
            return Info();
    }
};

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1), c0(n + 1), c1(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		c0[i] = c0[i - 1] + (a[i] == 0);
		c1[i] = c1[i - 1] + (a[i] == 1);
	}
	SegmentTree st(n, a);
	while(q --){
		int l, r;
		cin >> l >> r;
		int cnt0 = c0[r] - c0[l - 1];
		int cnt1 = c1[r] - c1[l - 1];
		if(cnt0 % 3 != 0 || cnt1 % 3 != 0){
			cout << -1 << '\n';
			continue;
		}
		cnt0 /= 3, cnt1 /= 3;
		cout << cnt0 + cnt1 + !(st.query(l, r).ok) << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}