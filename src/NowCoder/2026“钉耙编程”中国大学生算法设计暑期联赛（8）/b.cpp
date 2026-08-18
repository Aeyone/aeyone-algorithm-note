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
		T sum_a = 0;
		T sum_b = 0;
		int len = 0;
		friend Info operator+(const Info& l, const Info& r) {
			return {
				l.sum_a + r.sum_a,
				l.sum_b + r.sum_b,
				l.len + r.len
			};
		}
	};

	struct Lazy {
	    T A, B, t;
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

    void apply (int p, T A, T B, T t) {
        info[p].sum_a += A * info[p].len + info[p].sum_b * t;
        info[p].sum_b += B * info[p].len;
        lazy[p].A += A + lazy[p].B * t;
        lazy[p].B += B;
        lazy[p].t += t;
    }

	void pushup(int p) {
		info[p] = info[2 * p] + info[2 * p + 1];
	}

    void pushdown (int p) {
        if (lazy[p].A || lazy[p].B || lazy[p].t) {
            apply (2 * p, lazy[p].A, lazy[p].B, lazy[p].t);
            apply (2 * p + 1, lazy[p].A, lazy[p].B, lazy[p].t);
            lazy[p].A = lazy[p].B = lazy[p].t = 0;
        }
    }

	void build(int p, int l, int r, const vector<T>& a, const vector<T>& b) {
		if (l == r) {
			info[p] = {a[l], b[l], 1};
			return;
		}
		int mid = (l + r) / 2;
		build(2 * p, l, mid, a, b);
		build(2 * p + 1, mid + 1, r, a, b);
		pushup(p);
	}

	void modify(int p, int l, int r, int ql, int qr, T val) {
		if (ql <= l && r <= qr) {
			apply(p, 0, val, 0);
			return;
		}
		int mid = (l + r) / 2;
		pushdown(p);
		if (ql <= mid) modify(2 * p, l, mid, ql, qr, val);
		if (qr > mid) modify(2 * p + 1, mid + 1, r, ql, qr, val);
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

	void build(const vector<T>& a, const vector<T>& b) { // 1-based
		build(1, 1, n, a, b);
	}

	void modify(int ql, int qr, T val) {
		modify(1, 1, n, ql, qr, val);
	}

	Info query(int ql, int qr) {
		return query(1, 1, n, ql, qr);
	}
};

void solve () {
    int n, m;
    cin >> n >> m;
    vector<u64> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i] >> b[i];
    }

    SegmentTree<u64> seg(n);
    seg.build(a, b);

    for (int i = 1; i <= m; i ++) {
        seg.apply (1, 0, 0, 1);
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            u64 x;
            cin >> l >> r >> x;
            seg.modify (l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.query (l, r).sum_a << "\n";
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