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
        T max = 0;
        int idx = 0;
        friend Info operator+(const Info& l, const Info& r) {
        	if (l.max >= r.max) {
        		return {l.max, l.idx};
        	} else {
        		return {r.max, r.idx};
        	}
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
        build(1, 1, n);
    }

    void apply(int p, T val, int len) {
        info[p].max = val;
        lazy[p].add = val;
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

    void build(int p, int l, int r) {
        if (l == r) {
            info[p] = {0, l};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * p, l, mid);
        build(2 * p + 1, mid + 1, r);
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

    void modify(int ql, int qr, T val) {
        modify(1, 1, n, ql, qr, val);
    }

    Info query(int ql, int qr) {
    	if (qr < ql) return Info();
        return query(1, 1, n, ql, qr);
    }
};

int get(vector<int>& a, int x) {
	return 1 + lower_bound(a.begin(), a.end(), x) - a.begin();
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}

	vector<int> tot = a;
	sort(tot.begin(), tot.end());
	tot.erase(unique(tot.begin(), tot.end()), tot.end());

	int m = tot.size();
	SegmentTree<int> st(m + 1);
	vector<int> la(n), u(m + 1, -1);

	for (int i = 0; i < n; i ++) {
		int idx = get(tot, a[i]);
		auto res = st.query(1, idx - 1);

		st.modify(idx, idx, res.max + 1);
		la[i] = u[res.idx];

		u[idx] = i;
	}


	int x = u[st.query(1, m).idx];
	vector<int> res;
	while (x != -1) {
		res.push_back(a[x]);
		x = la[x];
	}
	reverse(res.begin(), res.end());

	cout << st.query(1, m).max << '\n';
	for (auto e : res) {
		cout << e << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}