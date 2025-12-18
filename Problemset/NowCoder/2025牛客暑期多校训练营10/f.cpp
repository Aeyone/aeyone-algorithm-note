#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct Info{
    i64 mx;
    int idx;
    Info(i64 x1 = 0, int x2 = 0) : mx(x1), idx(x2) {}
};

struct Lazy{
    i64 add, setL;
    bool need;
    Lazy(i64 x1 = 0, i64 x2 = 0, bool x3 = false) : add(x1), setL(x2), need(x3) {}
};

Info operator+(const Info &a, const Info &b){
    if(a.mx >= b.mx)
        return a;
    else
        return b;
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

    void applyAdd(int p, i64 val){
        info[p].mx += val;
        lazy[p].add += val;
    }

    void applySet(int p, i64 val){
        info[p].mx = val;
        lazy[p] = Lazy(0, val, true);
    }

    void down(int p){
        if(lazy[p].need){
            applySet(2 * p, lazy[p].setL);
            applySet(2 * p + 1, lazy[p].setL);
            lazy[p].need = false;
        }
        if(lazy[p].add != 0){
            applyAdd(2 * p, lazy[p].add);
            applyAdd(2 * p + 1, lazy[p].add);
            lazy[p].add = 0;
        }
    }

    void up(int p){
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void build(int p, int l, int r){
        if (l == r){
            info[p] = Info(0, l);
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid);
            build(2 * p + 1, mid + 1, r);
            up(p);
        }
    }
    void modify(int p, int l, int r, int L, int R, i64 val, int sign){
        if (L > r || R < l)
            return;

        if (L <= l && r <= R){
            if(sign == 1)
                applyAdd(p, val);
            if(sign == 2)
                applySet(p, val);
        }else{
            int mid = (l + r) / 2;
            down(p);
            modify(2 * p, l, mid, L, R, val, sign);
            modify(2 * p + 1, mid + 1, r, L, R, val, sign);
            up(p);
        }
    }
    //0-based
    void modify(int L, int R, i64 val, int sign){ 
        if(L <= R)
            modify(1, 1, n, L + 1, R + 1, val, sign);
    }
    auto query(){
        return info[1];
    }
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), nxt(n);
	map<int, int> lst;
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	for(int i = n - 1; i >= 0; i --){
		nxt[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	for(int i = 0; i < n; i ++)
		lst[a[i]] = i;

	map<int, bool> vis;
	SegmentTree st(n);
	int ans = 0, b1 = 2, b2 = 3;
	for(int i = 0; i <= n - 3; i ++){
		if(!vis[a[i]]){
			vis[a[i]] = true;
			int l = nxt[i] + 1, r = lst[a[i]];
			if(nxt[i] > 0)
				st.modify(l, r, 1, 1);
		}else{
			int l = i + 1, r = nxt[i] + 1;
			if(nxt[i] > 0)
				st.modify(l, r, -1, 1);
		}
		auto res = st.query();
		if(res.mx > ans)
			ans = res.mx, b1 = i + 2, b2 = res.idx;
	}
	cout << ans << '\n';
	cout << b1 << ' ' << b2 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}