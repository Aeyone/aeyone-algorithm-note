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

	int n;
	vector<Info> info;
	vector<Lazy> lazy;

	SegmentTree(int n = 0) { init(n); }

	void init(int n) {
		this->n = n;
		info.assign(n << 2, Info());
		lazy.assign(n << 2, Lazy());
	}

	void apply(int p, T val, int len) {
		info[p].sum += val * len;
		lazy[p].add += val;
	}

	void pushup(int p) {
		info[p] = info[2 * p] + info[2 * p + 1];
	}

	void pushdown(int p, int lsz, int rsz) {
		T& tag = lazy[p].add;
		if (tag != 0) {
			apply(2 * p, tag, lsz);
			apply(2 * p + 1, tag, rsz);
			tag = 0;
		}
	}

	void build(int p, int l, int r, const vector<T>& a) {
		if (l == r) {
			info[p] = {a[l]};
			return;
		}
		int mid = (l + r) / 2;
		build(2 * p, l, mid, a);
		build(2 * p + 1, mid + 1, r, a);
		pushup(p);
	}

	void modify(int p, int l, int r, int ql, int qr, T val) {
		if (ql <= l && r <= qr) {
			apply(p, val, r - l + 1);
			return;
		}
		int mid = (l + r) / 2;
		pushdown(p, mid - l + 1, r - mid);
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
		pushdown(p, mid - l + 1, r - mid);
		if (ql <= mid) res = res + query(2 * p, l, mid, ql, qr);
		if (qr > mid) res = res + query(2 * p + 1, mid + 1, r, ql, qr);
		return res;
	}

	int kth(int p, int l, int r, int k) {
		if (info[p].sum < k) {
			return -1;
		}
		if (l == r) {
			return l;
		}
		int mid = (l + r) / 2;
		pushdown(p, mid - l + 1, r - mid);
		if (info[2 * p].sum >= k) {
			return kth(2 * p, l, mid, k);
		} else {
			return kth(2 * p + 1, mid + 1, r, k - info[2 * p].sum);
		}
	}

	void build(const vector<T>& a) { // 1-based
		build(1, 1, n, a);
	}

	void modify(int ql, int qr, T val) {
		modify(1, 1, n, ql, qr, val);
	}

	Info query(int ql, int qr) {
		if (ql > qr) return {};
		return query(1, 1, n, ql, qr);
	}

	int kth(int k) {
		return kth(1, 1, n, k);
	}
};

void solve() {
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	vector<int> tot;
	for (auto &[op, x] : a) {
		cin >> op >> x;
		tot.push_back(x);
	}
	sort(tot.begin(), tot.end());
	tot.erase(unique(tot.begin(), tot.end()), tot.end());

	auto find = [&](int x)-> int {
		return lower_bound(tot.begin(), tot.end(), x) - tot.begin() + 1;
	};

	SegmentTree<int> tr(tot.size());

	for (auto [op, x] : a) {
		// cerr << 
		if (op == 1) {
			x = find(x);
			tr.modify(x, x, 1);
		}
		if (op == 2) {
			x = find(x);
			tr.modify(x, x, -1);
		}
		if (op == 3) {
			x = find(x);
			cout << tr.query(1, x - 1).sum + 1 << '\n';
		}
		if (op == 4) {
			cout << tot[tr.kth(x) - 1] << '\n';
		}
		if (op == 5) {
			x = find(x);
			int cnt = tr.query(1, x - 1).sum;
			cout << tot[tr.kth(cnt) - 1] << '\n';
		}
		if (op == 6) {
			x = find(x);
			int cnt = tr.query(1, x).sum;
			cout << tot[tr.kth(cnt + 1) - 1] << '\n';
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