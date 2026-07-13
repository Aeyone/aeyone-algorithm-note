#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

template<class T>
struct SegmentTree {
	struct Info {
		T sum = 0;
        friend Info operator+(const Info& l, const Info& r) {
			return {
				l.sum + r.sum
			};
		}
	};
	struct Lazy {
		T add = 0;
	};

	int n, idx = 0;
	vector<Info> info;
	vector<Lazy> lazy;
	vector<int> ls, rs;

	SegmentTree(int n = 0) { init(n); }

	void init(int n) {
		this->n = n;
		const int m = 1e5 * 70;
		info.assign(m, Info());
		lazy.assign(m, Lazy());
		ls.assign(m, 0);
		rs.assign(m, 0);
	}

	int clone(int p) {
		int i = ++ idx;
		info[i] = info[p];
		lazy[i] = lazy[p];
		ls[i] = ls[p], rs[i] = rs[p];
		return i;
	}

	void apply(int p, T val, int len) {
		info[p].sum += val * len;
		lazy[p].add += val;
	}

	void pushup(int p) {
		info[p] = info[ls[p]] + info[rs[p]];
	}

	void pushdown(int p, int lsz, int rsz) {
		T& tag = lazy[p].add;
		if (tag != 0) {
			ls[p] = clone(ls[p]);
			rs[p] = clone(rs[p]);
			apply(ls[p], tag, lsz);
			apply(rs[p], tag, rsz);
			tag = 0;
		}
	}

	int build(int l, int r, const vector<T>& a) {
        int p = ++ idx;
		if (l == r) {
			info[p].sum = a[l];
		} else {
            int mid = (l + r) / 2;
            ls[p] = build(l, mid, a);
            rs[p] = build(mid + 1, r, a);
            pushup(p);
        }
        return p;
	}

	int modify(int p, int l, int r, int ql, int qr, T val) {
        p = clone(p);
		if (ql <= l && r <= qr) {
			apply(p, val, r - l + 1);
		} else {
            int mid = (l + r) / 2;
			pushdown(p, mid - l + 1, r - mid);
            if (ql <= mid) ls[p] = modify(ls[p], l, mid, ql, qr, val);
            if (qr > mid) rs[p] = modify(rs[p], mid + 1, r, ql, qr, val);
			pushup(p);
        }
        return p;
	}

	Info query(int p, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) {
			return info[p];
		}
		Info res {};
		int mid = (l + r) / 2;
		pushdown(p, mid - l + 1, r - mid); 
		if (ql <= mid) res = res + query(ls[p], l, mid, ql, qr);
		if (qr > mid) res = res + query(rs[p], mid + 1, r, ql, qr);
		return res;	
	}

	int build(const vector<T>& a) {
		return build(1, n, a);
	}

    // p为要修改的版本的头编号，返回更改后版本的头编号
	int modify(int p, int ql, int qr, T val) { 
		return modify(p, 1, n, ql, qr, val);
	}

	// 注意：因为查询需要pushdown操作，每次查询也会产生logn个新节点
	Info query(int p, int ql, int qr) {
		return query(p, 1, n, ql, qr);
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<i64> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	SegmentTree<i64> st(n);
	vector<int> root(m + 1);
	root[0] = st.build(a);
	int T = 0;
	while (m --) {
		char op;
		cin >> op;
		if (op == 'C') {
			int l, r, d;
			cin >> l >> r >> d;
			root[T + 1] = st.modify(root[T], l, r, d);
			T ++;
		} else if (op == 'Q') {
			int l, r;
			cin >> l >> r;
			cout << st.query(root[T], l, r).sum << '\n';
		} else if (op == 'H') {
			int l, r , t;
			cin >> l >> r >> t;
			cout << st.query(root[t], l, r).sum << '\n';
		} else {
			int t;
			cin >> t;
			T = t;
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