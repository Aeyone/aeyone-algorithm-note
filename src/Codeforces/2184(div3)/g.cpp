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
    int mn = INF;
};

Info operator+(const Info &l, const Info &r){
    Info res;
    res.mn = min(l.mn, r.mn);
    return res;
}
 
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

    void up(int p){
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    
    void build(int p, int l, int r, vector<int> &a){
        if (l == r){
            info[p].mn = a[l];
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid, a);
            build(2 * p + 1, mid + 1, r, a);
            up(p);
        }
    }

    void modify(int p, int l, int r, int X, i64 val){
        if (X > r || X < l){
            return;
        }
        if (l == r){
            info[p].mn = val;
        }else{
            int mid = (l + r) / 2;
            modify(2 * p, l, mid, X, val);
            modify(2 * p + 1, mid + 1, r, X, val);
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
            res = query(2 * p, l, mid, L, R) + query(2 * p + 1, mid + 1, r, L, R);
        }
        return res;
    }
    //1-based
    void modify(int X, i64 val){
        modify(1, 1, n, X, val);
    }
    Info query(int L, int R){
        return query(1, 1, n, L, R);
    }
};

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	SegmentTree st(n, a);
	while (q --) {
		int sign;
		cin >> sign;
		if (sign == 1) {
			int i, x;
			cin >> i >> x;
			st.modify(i, x);
		}
		if (sign == 2) {
			int L, R;
			cin >> L >> R;
			int l = L, r = R, ans = -1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (st.query(L, mid).mn >= mid - L) {
					ans = mid, l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			if (ans != -1 && st.query(L, ans).mn == ans - L) {
				cout << 1 << '\n';
			} else {
				cout << 0 << '\n';
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}