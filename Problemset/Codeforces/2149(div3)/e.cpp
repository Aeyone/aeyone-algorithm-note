#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct Info{
    i64 sum = 0;
};

struct Lazy{
    i64 add = 0;
};

Info operator+(const Info &l, const Info &r){
   return Info(l.sum + r.sum);
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
        info[p].sum += val * siz;
        lazy[p].add += val;
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
        if (L > r || R < l)
            return;

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

    i64 query(int p, int l, int r, int L, int R){
        if(L > r || R < l)
            return 0;

        i64 res = 0;
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
    void modify(int L, int R, i64 val){
        modify(1, 1, n, L, R, val);
    }
    i64 query(int x){
        return query(1, 1, n, x, x);
    }
};

void solve() {
	int n, k ,ll, rr;
	cin >> n >> k >> ll >> rr;
	vector<int> a(n + 1), ne(n + 1, n + 1);
	map<int, int> la;
	SegmentTree st(n);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(la.find(a[i]) != la.end()){
			ne[la[a[i]]] = i;
		}
		la[a[i]] = i;
		st.modify(i, i, la.size());
	}
	i64 ans = 0;
	for(int i = 1; i <= n; i ++){
		int l = i + ll - 1, r = min(n, i + rr - 1);
		int R = -1;
		while(l <= r){
			int mid = (l + r) / 2;
			int tmp = st.query(mid);
			if(tmp <= k){
				R = (tmp == k ? mid : R);
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		l = i + ll - 1, r = min(n, i + rr - 1);
		int L = n + 1;
		while(l <= r){
			int mid = (l + r) / 2;
			int tmp = st.query(mid);
			if(tmp >= k){
				L = (tmp == k ? mid : L);
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		if(L <= R){
			ans += (R - L + 1);
		}
		st.modify(i, ne[i] - 1, -1);
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