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
        friend Info operator+(const Info& l, const Info& r) {
            return {
                std::max(l.max, r.max)
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
        info[p].max += val;
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
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	SegmentTree<int> st(n);
	st.build(a);

	while (m --) {
		int x;
		cin >> x;
		int ans = 0;
		while (x <= n) {
			if (a[x] > 1) {
				ans ++;
				int to = x + a[x];
				st.modify(x, x, -1);
				a[x] --;
				x = to;
				continue;
			}
			int l = x, r = n, to = n + 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (st.query(x, mid).max > 1) {
					to = mid, r = mid - 1;
				} else {
					l = mid + 1;
				}
			}
			ans += to - x;
			x = to;
		}
		cout << ans << '\n';
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