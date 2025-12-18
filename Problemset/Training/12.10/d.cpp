#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

struct Info{
    i64 sum = 0;
    int mn = INF;
};

struct Lazy{
    i64 add = 0;
};

Info operator+(const Info &l, const Info &r){
	Info res;
	res.mn = min(l.mn, r.mn);
	res.sum = l.sum + r.sum;
	return res;
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
        info[p].mn += val;
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
            info[p] = Info(l, l);
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid);
            build(2 * p + 1, mid + 1, r);
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
            return Info(0, INF);
        }
        Info res;
        if(L <= l && r <= R){
            res = info[p];
        }else{
            int mid = (l + r) / 2;
            down(p, mid - l + 1, r - mid);
            res = query(2 * p, l, mid, L, R) +  query(2 * p + 1, mid + 1, r, L, R);
        }
        return res;
    }
    //1-based
    void modify(int L, int R, i64 val){
        modify(1, 1, n, L, R, val);
    }
    Info query(int L, int R){
    	if(L > R){
    		return Info();
    	}
        return query(1, 1, n, L, R);
    }
};

void solve() {
	int n;
	cin >> n;
	vector<i64> a(2 * n + 1), pre(2 * n + 1);
	priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> heap;
	i64 ans = 0;
	for(int i = 1; i <= 2 * n; i ++) {
		cin >> a[i];
		ans += a[i];
		heap.push({a[i], i});
	}
	SegmentTree st(2 * n);
	int cnt = 0;
	while(cnt < n){
		auto [e, idx] = heap.top();
		heap.pop();
		if(st.query(idx - 1, idx - 1).sum > 0 && st.query(idx + 1, 2 * n).mn >= 2){
			ans -= e;
			st.modify(idx, 2 * n, -2);
			cnt ++;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}