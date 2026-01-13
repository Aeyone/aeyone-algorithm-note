#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct Info{
    i64 sum;
    Info(int x = 0) : sum(x) {}
};

struct Lazy{
    i64 add, setL;
    bool need;
    Lazy(i64 x1 = 0, i64 x2 = 0, bool x3 = false) : add(x1), setL(x2), need(x3) {}
};

Info operator+(const Info &a, const Info &b){
   	return (a.sum + b.sum);
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
    void applyAdd(int p, i64 val, int siz){
        info[p].sum += val * siz;
        lazy[p].add += val;
    }
    void applySet(int p, i64 val, int siz){
        info[p].sum = val * siz;
        lazy[p] = Lazy(0, val, true);
    }
    void down(int p, int sizL, int sizR){
        if(lazy[p].need){
            applySet(2 * p, lazy[p].setL, sizL);
            applySet(2 * p + 1, lazy[p].setL, sizR);
            lazy[p].need = false;
        }
        if(lazy[p].add != 0){
            applyAdd(2 * p, lazy[p].add, sizL);
            applyAdd(2 * p + 1, lazy[p].add, sizR);
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
    void modify(int p, int l, int r, int L, int R, i64 val, int sign){
        if (L > r || R < l)
            return;

        if (L <= l && r <= R){
            if(sign == 1)//增加
                applyAdd(p, val, r - l + 1);
            if(sign == 2)//重置
                applySet(p, val, r - l + 1);
        }else{
            int mid = (l + r) / 2;
            down(p, mid - l + 1, r - mid);
            modify(2 * p, l, mid, L, R, val, sign);
            modify(2 * p + 1, mid + 1, r, L, R, val, sign);
            up(p);//回溯
        }
    }
    i64 query(int p, int l, int r, int L, int R){
        i64 res = 0;
        if(L > r || R < l)
            return res;
        if(L <= l && r <= R){
            res = info[p].sum;
        }else{
            int mid = (l + r) / 2;
            down(p, mid - l + 1, r - mid);
            res += query(2 * p, l, mid, L, R);
            res += query(2 * p + 1, mid + 1, r, L, R);
        }
        return res;
    }
    //1-based
    void modify(int L, int R, i64 val, int sign){ 
        if(L <= R)
            modify(1, 1, n, L, R, val, sign);
    }
    i64 query(int L, int R){
        if(L <= R)
            return query(1, 1, n, L, R);
        else
        	return -1;
    }
};

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> d(n);
	d[0] = 1;
	for(int i = 1; i < n; i ++)
		d[i] = d[i - 1] + (s[i] == '(' ? 1 : -1);

	SegmentTree tr(n + 1);
	i64 ans = 0;
	for(int i = n - 2; i > 0; i --){
		ans += tr.query(d[i - 1], d[i - 1]);
		if(d[i] == 0)
			continue;
		tr.modify(d[i], d[i], 1, 1);//d[i]增加1
		tr.modify(1, (d[i] - 1) / 2, 0, 2);//重置
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}