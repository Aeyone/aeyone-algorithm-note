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
    i64 sum = 0;
    int mn = INFLL;
};

struct Lazy{
    i64 add = 0;
};

Info operator+(const Info &l, const Info &r){
    Info res;
    res.sum = l.sum + r.sum;
    res.mn = min(l.mn, r.mn);
    return res;
}
 
struct SegmentTree{
    int n;
    vector<Info> info;
    vector<Lazy> lazy;
 
    SegmentTree() {}
    SegmentTree(int _n, vector<int> &a) {
        init(_n, a);
    }

    void init(int _n, vector<int> &a){
        n = _n;
        info.assign(n << 2, Info());
        lazy.assign(n << 2, Lazy());
        build(1, 1, n, a);
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
    
    void build(int p, int l, int r, vector<int> &a){
        if (l == r){
            info[p] = {a[l], a[l]};
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid, a);
            build(2 * p + 1, mid + 1, r, a);
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
    void modify(int L, int R, int val){
        modify(1, 1, n, L, R, val);
    }
    Info query(int L, int R){
        return query(1, 1, n, L, R);
    }
    Info query(int X){
    	if (X == 0) {
    		return {0ll, 0ll};
    	}
        return query(1, 1, n, X, X);
    }
};

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	s = " " + s;
	vector<int> pre(n + 1);
	for (int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] + (s[i] == '(' ? 1 : -1);
	}
	SegmentTree st(n, pre);
	while (q --) {
		int sign, l, r;
		cin >> sign >> l >> r;
		if (sign == 1) {
			auto apply = [&](char c, int bg, int ed)->void{
				if (c == '(') {
					st.modify(bg, n, -1);
					st.modify(ed, n, 1);
				} else {
					st.modify(bg, n, 1);
					st.modify(ed, n, -1);
				}
			};
			apply(s[l], l, r);
			apply(s[r], r, l);
			swap(s[l], s[r]);
		}
		if (sign == 2) {
			if (st.query(r).sum - st.query(l - 1).sum == 0 && st.query(l, r).mn - st.query(l - 1).sum == 0) {
				cout << "Yes" << '\n';
			} else {
				cout << "No" << '\n';
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}