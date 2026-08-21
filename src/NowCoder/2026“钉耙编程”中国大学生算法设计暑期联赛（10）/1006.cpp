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
		int L = -1;
		int R = -1;
		friend Info operator+(const Info& l, const Info& r) {
			if (r.R == -1) return l;
			if (l.L == -1) return r;
			Info res = {l.sum + r.sum, l.L, r.R};
			if (l.R != r.L) res.sum ++;
			return res;
		}
	};
	struct Lazy {
		int set = -1;
		int rev = 0;
	};

	int n;
	vector<Info> info;
	vector<Lazy> lazy;

	SegmentTree(int n = 0) { init(n); }

	void init(int n) {
		this->n = n;
		info.assign(n << 2, Info());
		lazy.assign(n << 2, Lazy());
	}

	void applySet(int p, T val) {
		info[p] = {0, val, val};
		lazy[p] = {val, 0};
	}

	void applyRev(int p) {
		info[p].L = !info[p].L;
		info[p].R = !info[p].R;
		if (lazy[p].set != -1) {
			lazy[p].set = !lazy[p].set;
		} else {
			lazy[p].rev = !lazy[p].rev;
		}
	}

	void pushup(int p) {
		info[p] = info[2 * p] + info[2 * p + 1];
	}

	void pushdown(int p) {
		Lazy& tag = lazy[p];
		if (tag.set != -1) {
			applySet(2 * p, tag.set);
			applySet(2 * p + 1, tag.set);
			tag.set = -1;
		}
		if (tag.rev != 0) {
			applyRev(2 * p);
			applyRev(2 * p + 1);
			tag.rev = 0;
		}
	}

	void build(int p, int l, int r, const vector<T>& a) {
		if (l == r) {
			info[p] = {0, a[l], a[l]};
			return;
		}
		int mid = (l + r) / 2;
		build(2 * p, l, mid, a);
		build(2 * p + 1, mid + 1, r, a);
		pushup(p);
	}

	void setRange(int p, int l, int r, int ql, int qr, T val) {
		if (ql <= l && r <= qr) {
			applySet(p, val);
			return;
		}
		int mid = (l + r) / 2;
		pushdown(p);
		if (ql <= mid) setRange(2 * p, l, mid, ql, qr, val);
		if (qr > mid) setRange(2 * p + 1, mid + 1, r, ql, qr, val);
		pushup(p);
	}

	void reverse(int p, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) {
			applyRev(p);
			return;
		}
		int mid = (l + r) / 2;
		pushdown(p);
		if (ql <= mid) reverse(2 * p, l, mid, ql, qr);
		if (qr > mid) reverse(2 * p + 1, mid + 1, r, ql, qr);
		pushup(p);
	}

	Info query(int p, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) {
			return info[p];
		}
		Info res {};
		int mid = (l + r) / 2;
		pushdown(p);
		if (ql <= mid) res = res + query(2 * p, l, mid, ql, qr);
		if (qr > mid) res = res + query(2 * p + 1, mid + 1, r, ql, qr);
		return res;
	}

	void build(const vector<T>& a) { // 1-based
		build(1, 1, n, a);
	}

	void setRange(int ql, int qr, T val) {
		setRange(1, 1, n, ql, qr, val);
	}

	void reverse(int ql, int qr) {
		reverse(1, 1, n, ql, qr);
	}

	Info query(int ql, int qr) {
		return query(1, 1, n, ql, qr);
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) cin >> a[i];

	SegmentTree<int> seg(n);
	seg.build(a);
	
	while (m --) {
		int q;
		cin >> q;
		int l, r;
		cin >> l >> r;
		
		if (q == 1) {
			int x;
			cin >> x;
			seg.setRange(l, r, x);
		}
		if (q == 2) {
			seg.reverse(l, r);
		}
		if (q == 3) {
			cout << seg.query(l, r).sum << '\n';
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