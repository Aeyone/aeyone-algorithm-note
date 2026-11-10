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
		int pre = -1;
		int suf = -1;
		T cnt = 0;
		friend Info operator+(const Info& l, const Info& r) {
			if (l.pre == -1) return r;
			if (r.suf == -1) return l;
			return {
				l.pre,
				r.suf,
				l.cnt + r.cnt - (l.suf == r.pre)
			};
		}
	};
	struct Lazy {
		int id = -1;
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
		info[p].cnt = 1;
		info[p].pre = val;
		info[p].suf = val;
		lazy[p].id = val;
	}

	void pushup(int p) {
		info[p] = info[2 * p] + info[2 * p + 1];
	}

	void pushdown(int p, int lsz, int rsz) {
		T& tag = lazy[p].id;
		if (tag != -1) {
			apply(2 * p, tag, lsz);
			apply(2 * p + 1, tag, rsz);
			tag = -1;
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

	void build(const vector<T>& a) { // 1-based
		build(1, 1, n, a);
	}

	void modify(int ql, int qr, T val) {
		modify(1, 1, n, ql, qr, val);
	}

	Info query(int ql, int qr) {
		return query(1, 1, n, ql, qr);
	}
};

void solve() {
	int n, m, q;
	cin >> n >> m >> q;

	vector<int> o(m), x(m);
	vector<int> tot;
	for (int i = 0; i < m; i ++) {
		cin >> o[i] >> x[i];
		tot.push_back(x[i]);
		tot.push_back(min(n, x[i] + 1));
		tot.push_back(max(1, x[i] - 1));
	}

	sort(tot.begin(), tot.end());
	tot.erase(unique(tot.begin(), tot.end()), tot.end());

	auto idx = [&](int x)-> int {
		return lower_bound(tot.begin(), tot.end(), x) - tot.begin() + 1;
	};

	int N = tot.size();
	const int pow = 21;
	vector<array<int, pow + 1>> min(m), max(m);

	for(int i = 0; i < m; i ++) {
		x[i] = idx(x[i]);
		if (!o[i]) max[i][0] = x[i], min[i][0] = N + 1;
		else max[i][0] = 0, min[i][0] = x[i];
	}

	for(int p = 1; m >> p > 0; p ++) {
		for(int i = 0; i + (1 << p) <= m; i ++) {
			max[i][p] = std::max(max[i][p - 1], max[i + (1 << (p - 1))][p - 1]);
			min[i][p] = std::min(min[i][p - 1], min[i + (1 << (p - 1))][p - 1]);
		}
	}

	auto qpre = [&](int l, int r)->int{
		int p = __lg(r - l + 1);
		return std::max(max[l][p], max[r - (1 << p) + 1][p]);
	};

	auto qsuf = [&](int l, int r)->int{
		int p = __lg(r - l + 1);
		return std::min(min[l][p], min[r - (1 << p) + 1][p]);
	};

	SegmentTree<int> seg(N);

	vector<array<int, 2>> que(q);
	vector<int> u(q), ans(q);
	for (auto &[l, r] : que) {
		cin >> l >> r;
		l --, r --;
	}
	iota(u.begin(), u.end(), 0);

	sort(u.begin(), u.end(), [&](const int &a, const int &b)-> bool {
		return que[a][1] < que[b][1];
	});

	int R = 0;
	for (auto e : u) {
		auto [l, r] = que[e];
		while (R <= r) {
			int id = x[R];
			if (!o[R]) seg.modify(1, id, R);
			else seg.modify(id, N, R);
			R ++;
		}

		int pre = qpre(l, r);
		int suf = qsuf(l, r);
		
		if (pre >= suf) {
			ans[e] = seg.query(1, N).cnt;
		} else {
			if (pre > 0) ans[e] += seg.query(1, pre).cnt;
			if (suf < N + 1) ans[e] += seg.query(suf, N).cnt;
		}
	}
	for (int i = 0; i < q; i ++) {
		cout << ans[i] << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	while (t --) {
		solve();
	}
}